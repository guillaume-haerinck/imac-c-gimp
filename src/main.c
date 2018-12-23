#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "imac-img.h"
#include "image-loaders/ppm.h"
#include "luts/inversion.h"

// minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]

const char *getFilenameExtension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int main(int argc, char *argv[]) {
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
                // printf("Histogram asked \n");
            } else if (strcmp(argv[i], "-o") == 0) {
                imagePathIndex = i + 1;
            } else if (strcmp(argv[i], "ADDLUM") == 0) {
                // printf("Add luminosity filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMLUM") == 0) {
                // printf("Dim luminosity filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "ADDCON") == 0) {
                // printf("Add constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMCON") == 0) {
                // printf("Dim constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "INVERT") == 0) {
                printf("Invert filter activated\n");
                printf("%d", getPixelValue(&img, 0, 0, 0));
                invert(&img);
            } else if (strcmp(argv[i], "SEPIA") == 0) {
                // printf("Sepia filter power is: %s\n", argv[i + 1]);
            }
        }

        /* Save result */
        // TODO save histogram if asked
        if (imagePathIndex != -1) {
            ppm_save(argv[imagePathIndex], &img);
        } else {
            ppm_save("output.ppm", &img);
        }
        free(img.data);
    } else {
        printf("No input file provided ! \n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
