#include <stdlib.h>
#include <stdio.h>
#include "imac-lut1d.h"
#include "utils.h"

/* Constructor */
int lut_new(ImacLut1d* lut) {
    lut->size = 256;
    lut->data = (unsigned char*) malloc(lut->size * sizeof(unsigned char));
    if (lut->data == NULL) {
        printf("lut_new: Data is null");
        exit(EXIT_FAILURE);
    }

    // Init to no-effect lut
    for (unsigned int i = 0; i < lut->size; i++) {
        lut_set(lut, i, i);
    }
    return EXIT_SUCCESS;
}

/* Destructor */
int lut_delete(ImacLut1d* lut) {
    free(lut->data);
    return EXIT_SUCCESS;
}

/* Setters */
void lut_set(ImacLut1d* lut, unsigned int index, int value) {
    if (index >= lut->size) {
        printf("Error lut_getIndex: index superior to lut size\n");
        DEBUG_BREAK;
        exit(EXIT_FAILURE);
    }
    if (value > 255) { value = 255; }
    if (value < 0) { value = 0; }
    lut->data[index] = (unsigned char) value;
}

void lut_applyRgb(ImacLut1d* lut, ImacImg* img) {
    unsigned int brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            brightness = img_getPixelChannel(img, x, y, red);
            brightness = lut_get(lut, brightness);
            img_setPixelChannel(img, x, y, brightness, red);

            brightness = img_getPixelChannel(img, x, y, green);
            brightness = lut_get(lut, brightness);
            img_setPixelChannel(img, x, y, brightness, green);

            brightness = img_getPixelChannel(img, x, y, blue);
            brightness = lut_get(lut, brightness);
            img_setPixelChannel(img, x, y, brightness, blue);
        }
    }
}
/* Getters */
unsigned int lut_get(ImacLut1d* lut, unsigned int index) {
    if (index >= lut->size) {
        printf("Error lut_getIndex: index superior to lut size\n");
        DEBUG_BREAK;
        return(EXIT_FAILURE);
    }
    return lut->data[index];
}
