#include <stdio.h>
#include "inversion.h"

void inv_direct(ImacImg* img) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = (unsigned char) 255 - img_getPixelChannel(img, x, y, c);
                img_setPixelChannel(img, x, y, brightness, c);
            }
        }
    }
}

// TODO input lut pointer to do modification on the lut ?
void inv_lut(ImacImg* img) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c);
                brightness = _invertLookupTable[brightness];
                img_setPixelChannel(img, x, y, brightness, c);

            }
        }
    }
}
