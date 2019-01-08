#include <stdio.h>
#include <stdlib.h>
#include "imac-img.h"

/* Constructor */
int img_new(ImacImg* img, unsigned int width, unsigned int height) {
    if (width <=  0 || height <=  0) {
        printf("Error img_new: invalid image size\n");
        exit(EXIT_FAILURE);
    }

    img->width = width;
    img->height = height;
    img->data = malloc(3 * img->width * img->height * sizeof(unsigned char));
    if (img->data == NULL) {
        perror("img_new: Data is null");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

/* Destructor */
int img_delete(ImacImg* img) {
    free(img->data);
    return EXIT_SUCCESS;
}

/* Getters */
unsigned char img_getPixelChannel(ImacImg* img, unsigned int x, unsigned int y, enum img_Channel c) {
    if (x > img->width) {
        printf("Error img_getPixelChannel: x superior to img width\n");
        exit(EXIT_FAILURE);
    } else if (y > img->height) {
        printf("Error img_getPixelChannel: y superior to img height\n");
        exit(EXIT_FAILURE);
    }
    return img->data[y * img->width * 3 + x * 3 + c];
}

/* Setters */
void img_setToWhite(ImacImg* img) {
    int dataSize = 3 * img->width * img->height;
    for (int i = 0; i < dataSize; i++) {
        img->data[i] = 255;
    }
}

void img_setPixelChannel(ImacImg* img, unsigned int x, unsigned int y, unsigned char value, enum img_Channel c) {
    if (x > img->width) {
        printf("Error img_setPixelChannel: x superior to img width\n");
        exit(EXIT_FAILURE);
    } else if (y > img->height) {
        printf("Error img_setPixelChannel: y superior to img height\n");
        exit(EXIT_FAILURE);
    }
    img->data[y * img->width * 3 + x * 3 + c] = value;
}

void img_setPixelChannels(ImacImg* img, unsigned int x, unsigned int y, unsigned char value) {
    if (x > img->width) {
        printf("Error img_setPixelChannels: x superior to img width\n");
        exit(EXIT_FAILURE);
    } else if (y > img->height) {
        printf("Error img_setPixelChannels: y superior to img height\n");
        exit(EXIT_FAILURE);
    }
    img->data[y * img->width * 3 + x * 3 + red] = value;
    img->data[y * img->width * 3 + x * 3 + green] = value;
    img->data[y * img->width * 3 + x * 3 + blue] = value;
}
