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
#include "symmetry/symmetry.h"
#include "convolution/emboss.h"
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
    bool termHistogram = false;
    bool bLut3x1d = false;
    bool bLut1d = false;

    gui_printLogo();
    start = clock();
    
    unsigned int originalHistogram[4][256] ={{0},{0},{0},{0}};

    if (argc > 0) {
        ImacImg img;
        ImacImg histogram;
        ImacImg swapImg;
        ImacLut1d lut;
        ImacLut3x1d lut3x1d;
        ImacImg* ptrOnImage = &img;
        lut_new(&lut);
        lut3x1d_new(&lut3x1d);

        /* Handle filetype */
        if (strcmp("ppm", getFilenameExtension(argv[1])) == 0) {
            ppm_load(argv[1], ptrOnImage);
        } else {
            printf("Error in main: unknown file extension");
            return EXIT_FAILURE;
        }
        img_new(&swapImg, img.width, img.height);
        ImacImg* ptrOnSwap = &swapImg;

        /* Handle args */
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-histo") == 0) {
		    img_new(&histogram, 256, 150);
		    hist_rgb(ptrOnImage, &histogram);
		    bHistogram = true;
            } else if (strcmp(argv[i], "-v") == 0) {
		    termHistogram = true;
		    hist_buildHistogram(ptrOnImage, originalHistogram);
            }  else if (strcmp(argv[i], "-o") == 0) {
                if (argc == i + 2) {
                    outputPath = (char*) malloc(sizeof(char) * strlen(argv[i + 1]) + 1);
                    strcpy(outputPath, argv[i + 1]);
                    outputDir = getDirname(argv[i + 1]);
                }
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
                        img_setPixelChannels(ptrOnImage, x, y, img_getPixelGrayscale(ptrOnImage, x, y));
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
		    hist_buildHistogram(ptrOnImage, imgBrightnessSpectrum);
		    contrast_equalizeToLut1d(&lut, imgBrightnessSpectrum[rvb]);
		    bLut1d = true;
            } else if (strcmp(argv[i], "BLUR") == 0) {
                // TODO handle if convolution already exists
                blurValue = strtol(argv[i + 1], NULL, 10);
                printf("Applying %s with %d...\n", argv[i], blurValue);
                blur_imgRecursive(ptrOnImage, ptrOnSwap, blurValue);
                ImacImg* temp = ptrOnImage;
                ptrOnImage = ptrOnSwap;
                ptrOnSwap = temp;
		        printf("\n");
		        printf("[""\x1b[32m""%s SUCCESSFULLY APPLIED""\x1b[0m""]\n", argv[i]);
            } else if (strcmp(argv[i], "EDGE") == 0) {
                edge_img(ptrOnImage, ptrOnSwap);
                ImacImg* temp = ptrOnImage;
                ptrOnImage = ptrOnSwap;
                ptrOnSwap = temp;
            } else if (strcmp(argv[i], "VBLUR") == 0) {
                // TODO handle if convolution already exists
                blurValue = strtol(argv[i + 1], NULL, 10);
                int posX = strtol(argv[i + 2], NULL, 10);
                int posY = strtol(argv[i + 3], NULL, 10);
                printf("Applying %s with %d...\n", argv[i], blurValue);
                blur_vignette(ptrOnImage, ptrOnSwap, blurValue, posX, posY);
                ImacImg* temp = ptrOnImage;
                ptrOnImage = ptrOnSwap;
                ptrOnSwap = temp;
		        printf("\n");
		        printf("[""\x1b[32m""%s SUCCESSFULLY APPLIED""\x1b[0m""]\n", argv[i]);
            } else if (strcmp(argv[i], "KBLUR") == 0) {
                blur_imgKernel(ptrOnImage, ptrOnSwap);
                ImacImg* temp = ptrOnImage;
                ptrOnImage = ptrOnSwap;
                ptrOnSwap = temp;
            } else if (strcmp(argv[i], "EMBOSS") == 0) {
                emboss_img(ptrOnImage, ptrOnSwap);
                ImacImg* temp = ptrOnImage;
                ptrOnImage = ptrOnSwap;
                ptrOnSwap = temp;
            } else if (strcmp(argv[i], "FLIP_V") == 0) {
		    symmetry_flipV(ptrOnImage);
            } else if (strcmp(argv[i], "FLIP_H") == 0) {
		    symmetry_flipH(ptrOnImage);
            }

        }

        /* Apply filters */
        if (bLut1d) { lut_applyRgb(&lut, ptrOnImage); }
        if (bLut3x1d) { lut3x1d_apply(&lut3x1d, ptrOnImage); }
	if (termHistogram) {
		unsigned int imgBrightnessSpectrum[4][256] = {{0},{0},{0},{0}};
		hist_buildHistogram(ptrOnImage, imgBrightnessSpectrum);
		hist_printTerminal(originalHistogram[3], imgBrightnessSpectrum[3], 20);
	}
        if (bHistogram) {
            if (outputPath != NULL) {
                // Original histogram
                char histName[] = "/original-histogram.ppm";
                char* path = (char*) malloc(sizeof(char) * strlen(outputDir) * strlen(histName) + 2);
                strcpy(path, outputDir);
                strcat(path, histName);
                ppm_save(path, &histogram);
                free(path);

                // Modified image histogram
                img_new(&histogram, 256, 150);
                hist_rgb(ptrOnImage, &histogram);
                char histName2[] = "/output-histogram.ppm";
                char* path2 = (char*) malloc(sizeof(char) * strlen(outputDir) * strlen(histName2) + 2);
                strcpy(path2, outputDir);
                strcat(path2, histName2);
                ppm_save(path2, &histogram);
                free(path2);
            } else {
                ppm_save("./original-histogram.ppm", &histogram);
                img_new(&histogram, 256, 150);
                hist_rgb(ptrOnImage, &histogram);
                ppm_save("./output-histogram.ppm", &histogram);
            }
            img_delete(&histogram);
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
        img_delete(&swapImg);
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
