#include <stdio.h>
#include "inversion.h"

// ---------------------------------- PUBLIC FUNCTIONS

void inv_img(ImacImg* img) {
    unsigned int brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            brightness = 255 - img_getPixelChannel(img, x, y, red);
            img_setPixelChannel(img, x, y, brightness, red);

            brightness = 255 - img_getPixelChannel(img, x, y, green);
            img_setPixelChannel(img, x, y, brightness, green);

            brightness = 255 - img_getPixelChannel(img, x, y, blue);
            img_setPixelChannel(img, x, y, brightness, blue);
        }
    }
}

void inv_lut1d(ImacLut1d* lut) {
    for (unsigned int x = 0; x < lut->size; x++) {
        lut_set(lut, x, lut->size - x);
    }
}
