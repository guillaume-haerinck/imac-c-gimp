#include "contrast.h"
#include <stdio.h>

void contrast_addToLut(ImacLut* lut, unsigned char value) {
    int brightness = 0;
    float contrastFactor = (259.0 * (value+255.0))/(255.0*(259.0-value));
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = contrastFactor * (lut->data[i] - 128) + 128;
        if (brightness > 255) { brightness = 255; }
        if (brightness < 0) { brightness = 0; }
        lut->data[i] = (unsigned char) brightness;
	printf("contrast : %d\n",lut->data[i]);
    }
}

void contrast_dimToLut(ImacLut* lut, unsigned char value) {
    int brightness = 0;
    float contrastFactor = (259.0 * ((-value)+255.0))/(255.0*(259.0-(-value)));
    printf("value dim : %d\n", -value);
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = contrastFactor * (lut->data[i] - 128) + 128;
        if (brightness > 255) { brightness = 255; }
        if (brightness < 0) { brightness = 0; }
        lut->data[i] = (unsigned char) brightness;
	printf("contrast : %d\n",lut->data[i]);
    }
}
