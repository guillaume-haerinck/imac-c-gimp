#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"

int ppm_load(char* path, PPMImage* img) {
    // TODO check null allocation
    FILE* fp;
    char buffer[255];
    fp = fopen(path, "r");

    if (fp == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    fscanf(fp, "%s", buffer);
    img->format[0] = buffer[0];
    img->format[1] = buffer[1];
    img->format[2] = '\0';

    // TODO pass check if comments
    fscanf(fp, "%s", buffer);
    if (buffer[0] != '#') {
        sscanf(buffer, "%d", &img->width);
    }

    fscanf(fp, "%s", buffer);
    if (buffer[0] != '#') {
        sscanf(buffer, "%d", &img->height);
    }

    fscanf(fp, "%s", buffer);
    if (buffer[0] != '#') {
        sscanf(buffer, "%d", &img->maxColor);
    }


    fclose(fp);
    return EXIT_SUCCESS;
}
