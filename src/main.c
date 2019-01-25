#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "core/imac-img.h"
#include "core/imac-lut1d.h"
#include "core/imac-lut3x1d.h"
#include "core/utils.h"
#include "charts/histogram.h"
#include "image-loaders/ppm.h"
#include "luts/inversion.h"
#include "luts/luminosity.h"
#include "luts/contrast.h"
#include "luts/sepia.h"
#include "convolution/blur.h"
#include "convolution/edge.h"

// minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpuTimeUsed;
    char* outputDir = NULL;
    char* outputPath = NULL;
    int blurValue = 0;

    // Pass activation
    bool bHistogram = false;
    bool bLut3x1d = false;
    bool bLut1d = false;
    bool bConvolution = false;

    gui_printLogo();
    start = clock();

    if (argc > 0) {
        ImacImg img;
        ImacImg histogram;
        ImacImg convolutedImg;
        ImacLut1d lut;
        ImacLut3x1d lut3x1d;
        lut_new(&lut);
        lut3x1d_new(&lut3x1d);

        /* Handle filetype */
        if (strcmp("ppm", getFilenameExtension(argv[1])) == 0) {
            ppm_load(argv[1], &img);
        } else {
            printf("Error in main: unknown file extension");
            return EXIT_FAILURE;
        }
        img_new(&convolutedImg, img.width, img.height);

        /* Handle args */
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-histo") == 0) {
                img_new(&histogram, 256, 150);
                hist_rgb(&img, &histogram);
                bHistogram = true;
            } else if (strcmp(argv[i], "-o") == 0) {
                outputPath = (char*) malloc(sizeof(char) * strlen(argv[i + 1]) + 1);
                strcpy(outputPath, argv[i + 1]);
                outputDir = getDirname(argv[i + 1]);
            } else if (strcmp(argv[i], "ADDLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                lum_addToLut1d(&lut, (int) value);
                bLut1d = true;
            } else if (strcmp(argv[i], "DIMLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                lum_dimToLut1d(&lut, (int) value);
                bLut1d = true;
            } else if (strcmp(argv[i], "ADDCON") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                contrast_addToLut1d(&lut, (int) value);
                bLut1d = true;
            } else if (strcmp(argv[i], "DIMCON") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                contrast_dimToLut1d(&lut, (int) value);
                bLut1d = true;
            } else if (strcmp(argv[i], "INVERT") == 0) {
                inv_lut1d(&lut);
                bLut1d = true;
            } else if (strcmp(argv[i], "GRAY") == 0) {
                for (unsigned int x = 0; x < img.width; x++) {
                    for (unsigned int y = 0; y < img.height; y++) {
                        img_setPixelChannels(&img, x, y, img_getPixelGrayscale(&img, x, y));
                    }
                }
            } else if (strcmp(argv[i], "SEPIA") == 0) {
                sepia_addToLut3x1d(&lut3x1d);
                bLut3x1d = true;
            } else if (strcmp(argv[i], "SINCON") == 0) {
                int value = strtol(argv[i + 1], NULL, 10);
                contrast_sinToLut1d(&lut, value);
                bLut1d = true;
            } else if (strcmp(argv[i], "HISTEQ") == 0) {
                unsigned int imgBrightnessSpectrum[4][256] = {{0},{0},{0},{0}};
		        hist_buildHistogram(&img, imgBrightnessSpectrum);
                contrast_equalizeToLut1d(&lut, imgBrightnessSpectrum[rvb]);
                bLut1d = true;
            } else if (strcmp(argv[i], "BLUR") == 0) {
                // TODO handle if convolution already exists
                blurValue = strtol(argv[i + 1], NULL, 10);
                printf("Applying %s with %d...\n", argv[i], blurValue);
                blur_imgRecursive(&img, &convolutedImg, blurValue);
                bConvolution = true;
		        printf("\n");
		        printf("[""\x1b[32m""%s SUCCESSFULLY APPLIED""\x1b[0m""]\n", argv[i]);
            } else if (strcmp(argv[i], "EDGE") == 0) {
                edge_img(&img, &convolutedImg);
                bConvolution = true;
            } else if (strcmp(argv[i], "VBLUR") == 0) {
                // TODO handle if convolution already exists
                blurValue = strtol(argv[i + 1], NULL, 10);
                int posX = strtol(argv[i + 2], NULL, 10);
                int posY = strtol(argv[i + 3], NULL, 10);
                printf("Applying %s with %d...\n", argv[i], blurValue);
                blur_vignette(&img, &convolutedImg, blurValue, posX, posY);
                bConvolution = true;
		        printf("\n");
		        printf("[""\x1b[32m""%s SUCCESSFULLY APPLIED""\x1b[0m""]\n", argv[i]);
            } else if (strcmp(argv[i], "KBLUR") == 0) {
                blur_imgKernel(&img, &convolutedImg);
                bConvolution = true;
            }
        }

        /* Apply filters */
        ImacImg* ptrOnImage = &img;
        if (bLut1d) { lut_applyRgb(&lut, &img); }
        if (bLut3x1d) { lut3x1d_apply(&lut3x1d, &img); }
        if (bConvolution) { ptrOnImage = &convolutedImg; }
        if (bHistogram) {
            if (outputPath != NULL) {
                // Original histogram
                char histName[] = "/original-histogram.ppm";
                char* path = (char*) malloc(sizeof(char) * strlen(outputDir) * strlen(histName) + 1);
                strcpy(path, outputDir);
                strcat(path, histName);
                ppm_save(path, &histogram);

                // Modified image histogram
                img_new(&histogram, 256, 150);
                hist_rgb(&img, &histogram);
                char histName2[] = "/output-histogram.ppm";
                strcpy(path, outputDir);
                strcat(path, histName2);
                ppm_save(path, &histogram);
                free(path);
            } else {
                ppm_save("./original-histogram.ppm", &histogram);
                img_new(&histogram, 256, 150);
                hist_rgb(&img, &histogram);
                ppm_save("./output-histogram.ppm", &histogram);
            }
        }

        /* Save image */
	    if (outputPath != NULL) {
            ppm_save(outputPath, ptrOnImage);
        } else {
            ppm_save("./output.ppm", ptrOnImage);
        }

        /* Clean memory */
        lut_delete(&lut);
        lut3x1d_delete(&lut3x1d);
        img_delete(&img);
        img_delete(&convolutedImg);
        img_delete(&histogram);
        free(outputPath);
    } else {
        printf("No input file provided !\n");
        return EXIT_FAILURE;
    }

    end = clock();
    cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used (in seconds): %f\n", cpuTimeUsed);
    return EXIT_SUCCESS;
}
