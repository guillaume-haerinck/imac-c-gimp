#include "imac-lut.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor */
int lut_new(ImacLut* lut) {
    lut->size = 255;
    lut->data = malloc(lut->size * sizeof(unsigned char));
    if (lut->data == NULL) {
        perror("lut_new: Data is null");
        exit(EXIT_FAILURE);
    }

    // Init to no-effect lut
    for (unsigned int i = 0; i <= 255; i++) {
        lut->data[i] = (unsigned char) i;
    }
    return EXIT_SUCCESS;
}

/* Destructor */
int lut_delete(ImacLut* lut) {
    free(lut->data);
    return EXIT_SUCCESS;
}

/* Setters */
void lut_set(ImacLut* lut, unsigned int index, unsigned char value) {
    if (index > lut->size) {
        printf("Error lut_getIndex: index superior to lut size\n");
        exit(EXIT_FAILURE);
    }
    lut->data[index] = value;
}

int lut_applyRgb(ImacLut* lut, ImacImg* img) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c);
                brightness = lut_get(lut, brightness);
                img_setPixelChannel(img, x, y, brightness, c);
            }
        }
    }
}
/* Getters */
unsigned char lut_get(ImacLut* lut, unsigned int index) {
    if (index > lut->size) {
        printf("Error lut_getIndex: index superior to lut size\n");
        exit(EXIT_FAILURE);
    }
    return lut->data[index];
}

void lut_print(ImacLut* lut) {
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