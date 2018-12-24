#include "inversion.h"

// TODO use a LUT and not a direct manipulation
void invert(ImacImg* img) {
    unsigned char brightness = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = (unsigned char) 255 - getPixelValue(img, x, y, c);
                setPixelValue(img, x, y, c, brightness);
            }
        }
    }
}
