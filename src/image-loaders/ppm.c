#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"

int ppm_load(char* path, PPMImage* img) {
    FILE* fp;
    char buffer[64];

    if (img == NULL) {
        perror("ppm_load: Null img pointer");
        return EXIT_FAILURE;
    }
    fp = fopen(path, "rb");
    if (fp == NULL) {
        perror("ppm_load: Failed to open file");
        return EXIT_FAILURE;
    }

    // TODO check for P6
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

    // TODO do not save the header (+ because of that last pixel blue color out of allocated memory)
    img->data = malloc(3 * img->width * img->height);
    fseek(fp, 1, SEEK_CUR);
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
