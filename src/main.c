#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "imac-img.h"
#include "utils.h"
#include "charts/histogram.h"
#include "image-loaders/ppm.h"
#include "luts/inversion.h"
#include "luts/luminosity.h"

// minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    if (argc > 0) {
        ImacImg img;
        int imagePathIndex = -1;

        /* Handle filetype */
        if (strcmp("ppm", getFilenameExtension(argv[1])) == 0) {
            ppm_load(argv[1], &img);
        } else {
            printf("Error in main: unknown file extension");
            return EXIT_FAILURE;
        }

        /* Handle args */
        for(int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-histo") == 0) {
                ImacImg histogram;
                img_new(&histogram, 256, 150);
                hist_rgb(&img, &histogram);
                ppm_save("./histogram.ppm", &histogram);
                img_delete(&histogram);
            } else if (strcmp(argv[i], "-o") == 0) {
                imagePathIndex = i + 1;
            } else if (strcmp(argv[i], "ADDLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                addLuminosity(&img, (unsigned char) value);
            } else if (strcmp(argv[i], "DIMLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                dimLuminosity(&img, (unsigned char) value);
            } else if (strcmp(argv[i], "ADDCON") == 0) {
                // printf("Add constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMCON") == 0) {
                // printf("Dim constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "INVERT") == 0) {
                invert(&img);
            } else if (strcmp(argv[i], "SEPIA") == 0) {
                // printf("Sepia filter power is: %s\n", argv[i + 1]);
            }
        }

        /* Save result */
        if (imagePathIndex != -1) {
            ppm_save(argv[imagePathIndex], &img);
        } else {
            ppm_save("output.ppm", &img);
        }

        /* Clean memory */
        img_delete(&img);
    } else {
        printf("No input file provided ! \n");
        return EXIT_FAILURE;
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Cpu time used (in seconds): %f \n", cpu_time_used);
    return EXIT_SUCCESS;
}
