#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]

int main(int argc, char *argv[]) {
    if (argc > 0) {
        FILE* img;
        int i, j, max;
        char buf[255];
        printf("Input file is: %s \n", argv[1]);
        img = fopen(argv[1], "r");
        if (img == NULL) {
            perror("Failed to open file");
            return EXIT_FAILURE;
        }
        fscanf(img, "%s", buf);
        printf("file format : %s\n", buf );
        fscanf(img, "%s", buf);
        printf("width : %s\n", buf );
        fscanf(img, "%s", buf);
        printf("heigth : %s\n", buf );
        fscanf(img, "%s", buf);
        printf("max colour : %s\n", buf );
        fclose(img);

        /* Scan through args. */
        for(int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-histo") == 0) {
                printf("Histogram asked \n");
            } else if (strcmp(argv[i], "-o") == 0) {
                printf("Output name is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "ADDLUM") == 0) {
                printf("Add luminosity filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMLUM") == 0) {
                printf("Dim luminosity filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "ADDCON") == 0) {
                printf("Add constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMCON") == 0) {
                printf("Dim constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "INVERT") == 0) {
                printf("Invert filter activated\n");
            } else if (strcmp(argv[i], "SEPIA") == 0) {
                printf("Sepia filter power is: %s\n", argv[i + 1]);
            }
        }
    } else {
        printf("No input file provided ! \n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}