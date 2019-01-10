#include "imac-lut3x1d.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor */
int lut3x1d_new(ImacLut3x1d* lut3x1d) {
    lut3x1d->channelSize = 255;
    lut3x1d->dataR = malloc(lut3x1d->channelSize * sizeof(unsigned char));
    lut3x1d->dataG = malloc(lut3x1d->channelSize * sizeof(unsigned char));
    lut3x1d->dataB = malloc(lut3x1d->channelSize * sizeof(unsigned char));
    if (lut3x1d->dataR == NULL) {
        perror("lut3x1d_new: DataR is null");
        exit(EXIT_FAILURE);
    }
    if (lut3x1d->dataG == NULL) {
        perror("lut3x1d_new: DataG is null");
        exit(EXIT_FAILURE);
    }
    if (lut3x1d->dataB == NULL) {
        perror("lut3x1d_new: DataB is null");
        exit(EXIT_FAILURE);
    }

    // Init to no-effect lut3x1d
    for (unsigned int i = 0; i <= lut3x1d->channelSize; i++) {
	    lut3x1d->dataR[i] = (unsigned char) i;
	    lut3x1d->dataG[i] = (unsigned char) i;
	    lut3x1d->dataB[i] = (unsigned char) i;
    }
    return EXIT_SUCCESS;
}

/* Destructor */
int lut3x1d_delete(ImacLut3x1d* lut3x1d) {
    free(lut3x1d->dataR);
    free(lut3x1d->dataG);
    free(lut3x1d->dataB);
    return EXIT_SUCCESS;
}

/* Setters */
void lut3x1d_set(ImacLut3x1d* lut3x1d, unsigned int index, unsigned char value, enum img_Channel c) {
    if (index > lut3x1d->channelSize) {
        printf("Error lut3x1d_getIndex: index superior to lut3x1d channel size\n");
        exit(EXIT_FAILURE);
    }

    switch(c) {
    	case red:
            lut3x1d->dataR[index] = value;
            break;

    	case green:
            lut3x1d->dataG[index] = value;
            break;

    	case blue:
            lut3x1d->dataB[index] = value;
            break;

        default:
            printf("Error lut3x1d_set: Unknown color\n");
            exit(EXIT_FAILURE);
    }
}

void lut3x1d_apply(ImacLut3x1d* lut3x1d, ImacImg* img) {
    unsigned char meanBrightness = 0;
    unsigned char brightnessR = 0;
    unsigned char brightnessG = 0;
    unsigned char brightnessB = 0;

    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            brightnessR = img_getPixelChannel(img, x, y, red);
            brightnessG = img_getPixelChannel(img, x, y, green);
            brightnessB = img_getPixelChannel(img, x, y, blue);
	    meanBrightness = 0.3*brightnessR + 0.59*brightnessG + 0.11*brightnessB;

            brightnessR = lut3x1d_get(lut3x1d, meanBrightness, red);
            img_setPixelChannel(img, x, y, brightnessR, red);

            brightnessG = lut3x1d_get(lut3x1d, meanBrightness, green);
            img_setPixelChannel(img, x, y, brightnessG, green);

            brightnessB = lut3x1d_get(lut3x1d, meanBrightness, blue);
            img_setPixelChannel(img, x, y, brightnessB, blue);
        }
    }
}

/* Getters */
unsigned char lut3x1d_get(ImacLut3x1d* lut3x1d, unsigned int index, enum img_Channel c) {
    if (index > lut3x1d->channelSize) {
        printf("Error lut3x1d_get: index superior to lut3x1d size\n");
        exit(EXIT_FAILURE);
    }

    switch(c) {
    	case red: return lut3x1d->dataR[index];
    	case green: return lut3x1d->dataG[index];
    	case blue: return lut3x1d->dataB[index];
        default:
            printf("Error lut3x1d_get: Unknown color\n");
            exit(EXIT_FAILURE);
    }
}

void lut3x1d_print(ImacLut3x1d* lut3x1d) {
    printf("in: ");
    for (int i = 0; i < lut3x1d->channelSize; i++) {
        printf("R:%d ", i);
        printf("G:%d ", i);
        printf("B:%d ", i);
    }
    printf("\n");

    printf("to: ");
    for (int i = 0; i <= lut3x1d->channelSize; i++) {
        printf("R:%d ", lut3x1d->dataR[i]);
        printf("G:%d ", lut3x1d->dataG[i]);
        printf("B:%d ", lut3x1d->dataB[i]);
    }
    printf("\n");
}
