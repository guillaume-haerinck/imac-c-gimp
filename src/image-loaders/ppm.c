#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ppm.h"

#define HEADER_LINE_MAX_LENGTH 70

int ppm_load(char* path, ImacImg* img) {
    FILE* fp;
    char buffer[HEADER_LINE_MAX_LENGTH];
    unsigned int width = 0;
    unsigned int height = 0;
    enum img_Format format = P6;

    if (img == NULL) {
        perror("ppm_load: Null img pointer");
        return EXIT_FAILURE;
    }
    fp = fopen(path, "rb");
    if (fp == NULL) {
        perror("ppm_load: Failed to open file");
        return EXIT_FAILURE;
    }

    char ppmFormat[3];
    fscanf(fp, "%s", buffer);
    ppmFormat[0] = buffer[0];
    ppmFormat[1] = buffer[1];
    ppmFormat[2] = '\0';
    if (strcmp(ppmFormat, "P6") == 0) {
        format = P6;
    } else if (strcmp(ppmFormat, "P5") == 0) {
        format = P5;
    } else if (strcmp(ppmFormat, "P4") == 0) {
        format = P4;
    } else if (strcmp(ppmFormat, "P3") == 0) {
        format = P3;
    } else if (strcmp(ppmFormat, "P2") == 0) {
        format = P2;
    } else if (strcmp(ppmFormat, "P1") == 0) {
        format = P1;
    } else {
        printf("Error ppm_load: Unknown extension\n");
        return EXIT_FAILURE;
    }

    fscanf(fp, "%s", buffer);
    while (buffer[0] == '#') { fgets(buffer, HEADER_LINE_MAX_LENGTH, fp); fscanf(fp, "%s", buffer);} // Go to newline while comment
    sscanf(buffer, "%d", &width);

    fscanf(fp, "%s", buffer);
    while (buffer[0] == '#') { fgets(buffer, HEADER_LINE_MAX_LENGTH, fp); fscanf(fp, "%s", buffer);} // Go to newline while comment
    sscanf(buffer, "%d", &height);

    if (format != P1) {
        fscanf(fp, "%s", buffer);
        while (buffer[0] == '#') { fgets(buffer, HEADER_LINE_MAX_LENGTH, fp); fscanf(fp, "%s", buffer);} // Go to newline while comment
    }

    img_new(img, width, height);
    fseek(fp, 1, SEEK_CUR); // Skip newline char
    fread(img->data, 3 * img->width, img->height, fp); // Parse binary data to image
    fclose(fp);
    return EXIT_SUCCESS;
}

int ppm_save(char* path, ImacImg* img) {
    // TODO check if data
    FILE* fp = fopen(path, "wb");
    if (fp == NULL) {
        perror("ppm_save: cannot create new file");
        return EXIT_FAILURE;
    }

    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    fwrite(img->data, sizeof(unsigned char), 3 * img->width * img->height, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}
