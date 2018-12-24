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
    img->data = malloc(3 * img->width * img->height);
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

unsigned char img_getPixelChannel(ImacImg* img, int x, int y, enum img_Channel c) {
    return img->data[y * img->width * 3 + x * 3 + c];
}

/* Setters */
void img_setImageToWhite(ImacImg* img) {
    int dataSize = 3 * img->width * img->height;
    for (int i = 0; i < dataSize; i++) {
        img->data[i] = 255;
    }
}

void img_setPixelChannel(ImacImg* img, int x, int y, unsigned char value, enum img_Channel c) {
    img->data[y * img->width * 3 + x * 3 + c] = value;
}

void img_setPixelChannels(ImacImg* img, int x, int y, unsigned char value) {
    img->data[y * img->width * 3 + x * 3 + red] = value;
    img->data[y * img->width * 3 + x * 3 + green] = value;
    img->data[y * img->width * 3 + x * 3 + blue] = value;
}
