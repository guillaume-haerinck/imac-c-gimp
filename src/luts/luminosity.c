#include "luminosity.h"
#include <stdio.h>

// TODO use a LUT and not a direct manipulation

// Cpu time used: 0.000302 seconds for 62x56px rgb image
void addLuminosity(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c) + value;
                if (brightness > 255) { brightness = 255; }
                img_setPixelChannel(img, x, y, c, brightness);
            }
        }
    }
}

void dimLuminosity(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c) - value;
                if (brightness < 0) { brightness = 0; }
                img_setPixelChannel(img, x, y, brightness, c);
            }
        }
    }
}