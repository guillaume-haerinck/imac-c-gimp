#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"

#define HEADER_LINE_MAX_LENGTH 70

int ppm_load(char* path, PPMImage* img) {
    FILE* fp;
    char buffer[HEADER_LINE_MAX_LENGTH];

    if (img == NULL) {
        perror("ppm_load: Null img pointer");
        return EXIT_FAILURE;
    }
    fp = fopen(path, "rb");
    if (fp == NULL) {
        perror("ppm_load: Failed to open file");
        return EXIT_FAILURE;
    }

    fscanf(fp, "%s", buffer);
    img->format[0] = buffer[0];
    img->format[1] = buffer[1];
    img->format[2] = '\0';

    fscanf(fp, "%s", buffer);
    while (buffer[0] == '#') { fgets(buffer, HEADER_LINE_MAX_LENGTH, fp); fscanf(fp, "%s", buffer);} // Go to newline while comment
    sscanf(buffer, "%d", &img->width);

    fscanf(fp, "%s", buffer);
    while (buffer[0] == '#') { fgets(buffer, HEADER_LINE_MAX_LENGTH, fp); fscanf(fp, "%s", buffer);} // Go to newline while comment
    sscanf(buffer, "%d", &img->height);

    if (strcmp(img->format, "P1") != 0) {
        fscanf(fp, "%s", buffer);
        while (buffer[0] == '#') { fgets(buffer, HEADER_LINE_MAX_LENGTH, fp); fscanf(fp, "%s", buffer);} // Go to newline while comment
        sscanf(buffer, "%d", &img->maxColor);
    } else {
        img->maxColor = 1;
    }

    img->data = malloc(3 * img->width * img->height);
    fseek(fp, 1, SEEK_CUR); // Skip newline char
    fread(img->data, 3 * img->width, img->height, fp);
    fclose(fp);
    return EXIT_SUCCESS;
}

unsigned char ppm_getPixelColor(PPMImage* img, int x, int y, enum Color c) {
    if (y > img->height) { printf("Warning ppm_getPixelColor: y position superior to image height\n"); }
    if (x > img->width) { printf("Warning ppm_getPixelColor: x position superior to image width\n"); }
    return img->data[y * img->width * 3 + x * 3 + c];
}

Pixel ppm_getPixel(PPMImage* img, int x, int y) {
    if (y > img->height) { printf("Warning ppm_getPixel: y position superior to image height\n"); }
    if (x > img->width) { printf("Warning ppm_getPixel: x position superior to image width\n"); }
    Pixel pix;
    pix.red = img->data[y * img->width * 3 + x * 3 + red];
    pix.green = img->data[y * img->width * 3 + x * 3 + green];
    pix.blue = img->data[y * img->width * 3 + x * 3 + blue];
    return pix;
}

int ppm_save() {

}
