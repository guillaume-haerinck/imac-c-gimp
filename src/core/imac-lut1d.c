#include "imac-lut1d.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor */
int lut_new(ImacLut1d* lut) {
    lut->size = 255;
    lut->data = malloc(lut->size * sizeof(int));
    if (lut->data == NULL) {
        perror("lut_new: Data is null");
        exit(EXIT_FAILURE);
    }

    // Init to no-effect lut
    for (unsigned int i = 0; i <= lut->size; i++) {
        lut->data[i] = (int) i;
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
    if (index > lut->size) {
        printf("Error lut_getIndex: index superior to lut size\n");
        exit(EXIT_FAILURE);
    }
    lut->data[index] = value;
}

void lut_applyRgb(ImacLut1d* lut, ImacImg* img) {
    int brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c);
                brightness = lut_get(lut, brightness);
		if (brightness > 255) brightness = 255;
		else if (brightness < 0) brightness = 0;
                img_setPixelChannel(img, x, y, (unsigned char) brightness, c);
            }
        }
    }
}
/* Getters */
int lut_get(ImacLut1d* lut, unsigned int index) {
    if (index > lut->size) {
        printf("Error lut_getIndex: index superior to lut size\n");
        exit(EXIT_FAILURE);
    }
    return lut->data[index];
}

void lut_print(ImacLut1d* lut) {
    printf("in: ");
    for (int i = 0; i <= lut->size; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("to: ");
    for (int i = 0; i <= lut->size; i++) {
        printf("%d ", lut->data[i]);
    }
    printf("\n");
}
