#include <stdio.h>
#include "inversion.h"

void inv_img(ImacImg* img) {
    int brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = (unsigned char) 255 - img_getPixelChannel(img, x, y, c);
                img_setPixelChannel(img, x, y, brightness, c);
            }
        }
    }
}

void inv_lut1d(ImacLut1d *lut) {
    for (unsigned int x = 0; x <= lut->size; x++) {
        lut_set(lut, x, _invertLookupTable[x]);
    }
}
