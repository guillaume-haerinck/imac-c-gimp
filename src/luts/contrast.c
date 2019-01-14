#include "contrast.h"
#include <stdio.h>

void contrast_addToLut1d(ImacLut1d *lut, int value) {
    double brightness = 0;
    double contrastFactor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value));
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = contrastFactor * (lut->data[i] - 128) + 128;
        if (brightness > 255) { brightness = 255; }
        if (brightness < 0) { brightness = 0; }
        lut->data[i] = (int) brightness;
    }
}

void contrast_dimToLut1d(ImacLut1d *lut, int value) {
    double brightness = 0;
    double contrastFactor = (259.0 * ((-value) + 255.0)) / (255.0 * ( 259.0 - (-value)));
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = contrastFactor * (lut->data[i] - 128) + 128;
        if (brightness > 255) { brightness = 255; }
        if (brightness < 0) { brightness = 0; }
        lut->data[i] = (int) brightness;
    }
}
