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
#include "convolution/convolution.h"

// minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpuTimeUsed;
    bool bHistogram = false;
    bool bLut3x1d = false;
    bool convolutionImg = false;
    int conValue;
    start = clock();

    if (argc > 0) {
        ImacImg img;
        ImacImg convolutedImg;
        ImacLut1d lut;
        ImacLut3x1d lut3x1d;
        lut_new(&lut);
        lut3x1d_new(&lut3x1d);
        int imagePathIndex = -1;

        /* Handle filetype */
        if (strcmp("ppm", getFilenameExtension(argv[1])) == 0) {
            ppm_load(argv[1], &img);
        } else {
            printf("Error in main: unknown file extension");
            return EXIT_FAILURE;
        }

        /* Handle args */
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-histo") == 0) {
                ImacImg histogram;
                img_new(&histogram, 256, 150);
                hist_rgb(&img, &histogram);
                // TODO append histogram to argv[1] name + Use the output path
                ppm_save("./original-histogram.ppm", &histogram);
                img_delete(&histogram);
                bHistogram = true;
            } else if (strcmp(argv[i], "-o") == 0) {
                imagePathIndex = i + 1;
            } else if (strcmp(argv[i], "ADDLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                lum_addToLut1d(&lut, (unsigned char) value);
            } else if (strcmp(argv[i], "DIMLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                lum_dimToLut1d(&lut, (unsigned char) value);
            } else if (strcmp(argv[i], "ADDCON") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                contrast_addToLut1d(&lut, (unsigned char) value);
            } else if (strcmp(argv[i], "DIMCON") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                if (value > 255) { value = 255; }
                contrast_dimToLut1d(&lut, (unsigned char) value);
            } else if (strcmp(argv[i], "INVERT") == 0) {
                inv_lut1d(&lut);
            } else if (strcmp(argv[i], "SEPIA") == 0) {
                sepia_addToLut3x1d(&lut3x1d);
                bLut3x1d = true;
            } else if (strcmp(argv[i], "SINCON") == 0) {
                int value = strtol(argv[i + 1], NULL, 10);
                contrast_Sin(&lut, value);
            } else if (strcmp(argv[i], "HISTEQ") == 0) {
                ImacImg histogramTab;
		unsigned int imgBrightnessSpectrum[4][256] = {{0},{0},{0},{0}};
		build_histogram(&img, imgBrightnessSpectrum);
                contrast_Equalizer(&lut, imgBrightnessSpectrum[rvb]);
            } else if (strcmp(argv[i], "BLUR") == 0) {
		img_new(&convolutedImg, img.width, img.height);
                conValue = strtol(argv[i + 1], NULL, 10);
		convolutionImg = true;
            }


        }

        /* Save result */
        lut_applyRgb(&lut, &img);
        if (bLut3x1d) { lut3x1d_apply(&lut3x1d, &img); }
	ImacImg* ptrOnImage = &img;
        if (convolutionImg) {
                convolution_blur(&img, &convolutedImg, conValue);
		ptrOnImage = &convolutedImg;
	}
        if (bHistogram) {
            ImacImg histogram;
            img_new(&histogram, 256, 150);
            hist_rgb(&img, &histogram);
            // TODO append histogram to argv[1] name + Use the output path
            ppm_save("./output-histogram.ppm", &histogram);
            img_delete(&histogram);
        }
        
	    if (imagePathIndex != -1) {
            ppm_save(argv[imagePathIndex], ptrOnImage);
        } else {
            ppm_save("output.ppm", ptrOnImage);
        }

        /* Clean memory */
        lut_delete(&lut);
        lut3x1d_delete(&lut3x1d);
        img_delete(&img);
    } else {
        printf("No input file provided !\n");
        return EXIT_FAILURE;
    }

    end = clock();
    cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used (in seconds): %f\n", cpuTimeUsed);
    return EXIT_SUCCESS;
}
