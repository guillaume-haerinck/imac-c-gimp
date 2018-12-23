#include "luminosity.h"
#include <stdio.h>

void addLuminosity(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    printf("%d\n", value);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = getPixelValue(img, x, y, c) + value;
                if (brightness > 255) { brightness = 255; }
                setPixelValue(img, x, y, c, brightness);
            }
        }
    }
}

void dimLuminosity(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = getPixelValue(img, x, y, c) - value;
                if (brightness < 0) { brightness = 0; }
                setPixelValue(img, x, y, c, brightness);
            }
        }
    }
}