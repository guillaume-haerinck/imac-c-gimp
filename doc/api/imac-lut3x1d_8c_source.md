---
search:
    keywords: ['imac-lut3x1d.c', 'file']
---

# imac-lut3x1d.c File Reference

**[Go to the documentation of this file.](imac-lut3x1d_8c.md)**
Source: `src/core/imac-lut3x1d.c`

    
    
    
    
    
      
    
    
    
```cpp
#include "imac-lut3x1d.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor */
int lut3d_new(ImacLut3x1d* lut3d) {
    lut3d->channelSize = 255;
    lut3d->dataR = malloc(lut3d->channelSize * sizeof(unsigned char));
    lut3d->dataG = malloc(lut3d->channelSize * sizeof(unsigned char));
    lut3d->dataB = malloc(lut3d->channelSize * sizeof(unsigned char));
    if (lut3d->dataR == NULL) {
        perror("lut3d_new: DataR is null");
        exit(EXIT_FAILURE);
    }
    if (lut3d->dataG == NULL) {
        perror("lut3d_new: DataG is null");
        exit(EXIT_FAILURE);
    }
    if (lut3d->dataB == NULL) {
        perror("lut3d_new: DataB is null");
        exit(EXIT_FAILURE);
    }

    // Init to no-effect lut3d
    for (unsigned int i = 0; i <= lut3d->channelSize; i++) {
        lut3d->dataR[i] = (unsigned char) i;
    }
    for (unsigned int i = 0; i <= lut3d->channelSize; i++) {
        lut3d->dataG[i] = (unsigned char) i;
    }
    for (unsigned int i = 0; i <= lut3d->channelSize; i++) {
        lut3d->dataB[i] = (unsigned char) i;
    }
    return EXIT_SUCCESS;
}

/* Destructor */
int lut3d_delete(ImacLut3x1d* lut3d) {
    free(lut3d->dataR);
    free(lut3d->dataG);
    free(lut3d->dataB);
    return EXIT_SUCCESS;
}

/* Setters */
void lut3d_set(ImacLut3x1d* lut3d, unsigned int index, unsigned char value, enum img_Channel c) {
    if (index > lut3d->channelSize) {
        printf("Error lut3d_getIndex: index superior to lut3d channel size\n");
        exit(EXIT_FAILURE);
    }

    switch(c) {
        case red:
            lut3d->dataR[index] = value;
            break;

        case green:
            lut3d->dataG[index] = value;
            break;

        case blue:
            lut3d->dataB[index] = value;
            break;

        default:
            printf("Error lut3d_set: Unknown color\n");
            exit(EXIT_FAILURE);
    }
}

void lut3d_apply(ImacLut3x1d* lut3d, ImacImg* img) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            brightness = img_getPixelChannel(img, x, y, red);
            brightness = lut3d_get(lut3d, brightness, red);
            img_setPixelChannel(img, x, y, brightness, red);

            brightness = img_getPixelChannel(img, x, y, green);
            brightness = lut3d_get(lut3d, brightness, green);
            img_setPixelChannel(img, x, y, brightness, green);

            brightness = img_getPixelChannel(img, x, y, blue);
            brightness = lut3d_get(lut3d, brightness, blue);
            img_setPixelChannel(img, x, y, brightness, blue);
        }
    }
}

/* Getters */
unsigned char lut3d_get(ImacLut3x1d* lut3d, unsigned int index, enum img_Channel c) {
    if (index > lut3d->channelSize) {
        printf("Error lut3d_get: index superior to lut3d size\n");
        exit(EXIT_FAILURE);
    }

    switch(c) {
        case red: return lut3d->dataR[index];
        case green: return lut3d->dataG[index];
        case blue: return lut3d->dataB[index];
        default:
            printf("Error lut3d_get: Unknown color\n");
            exit(EXIT_FAILURE);
    }
}

void lut3d_print(ImacLut3x1d* lut3d) {
    printf("in: ");
    for (int i = 0; i < lut3d->channelSize; i++) {
        printf("R:%d ", i);
        printf("G:%d ", i);
        printf("B:%d ", i);
    }
    printf("\n");

    printf("to: ");
    for (int i = 0; i <= lut3d->channelSize; i++) {
        printf("R:%d ", lut3d->dataR[i]);
        printf("G:%d ", lut3d->dataG[i]);
        printf("B:%d ", lut3d->dataB[i]);
    }
    printf("\n");
}
```


    
  