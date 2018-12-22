#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "image-loaders/ppm.h"

// minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]

int main(int argc, char *argv[]) {
    if (argc > 0) {
        PPMImage ppm;
        ppm_load(argv[1], &ppm);
        // printf("%s\n", ppm.format);
        // printf("%d\n", ppm.width);
        // printf("%d\n", ppm.height);
        // printf("%d\n", ppm.maxColor);
        Pixel pix = ppm_getPixel(&ppm, 191, 127);
        printf("r: %d, g: %d, b: %d \n", pix.red, pix.green, pix.blue);

        /* Scan through args. */
        for(int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-histo") == 0) {
                // printf("Histogram asked \n");
            } else if (strcmp(argv[i], "-o") == 0) {
                // printf("Output name is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "ADDLUM") == 0) {
                // printf("Add luminosity filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMLUM") == 0) {
                // printf("Dim luminosity filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "ADDCON") == 0) {
                // printf("Add constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMCON") == 0) {
                // printf("Dim constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "INVERT") == 0) {
                // printf("Invert filter activated\n");
            } else if (strcmp(argv[i], "SEPIA") == 0) {
                // printf("Sepia filter power is: %s\n", argv[i + 1]);
            }
        }
        free(ppm.data);
    } else {
        printf("No input file provided ! \n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}