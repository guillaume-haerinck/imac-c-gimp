#include "luminosity.h"
#include <stdio.h>

void lum_addToImg(ImacImg* img, int value) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (unsigned char c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c) + value;
                if (brightness > 255) { brightness = 255; }
                img_setPixelChannel(img, x, y, c, brightness);
            }
        }
    }
}

void lum_addToLut1d(ImacLut1d *lut, int value) {
    int brightness = 0;
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = lut->data[i] + value;
        lut->data[i] = brightness;
    }
}

void lum_dimToImg(ImacImg* img, int value) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (unsigned char c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c) - value;
                if (brightness < 0) { brightness = 0; }
                img_setPixelChannel(img, x, y, brightness, c);
            }
        }
    }
}

void lum_dimToLut1d(ImacLut1d *lut, int value) {
    int brightness = 0;
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = lut_get(lut, i) - value;
        lut_set(lut, i, brightness);
    }
}
