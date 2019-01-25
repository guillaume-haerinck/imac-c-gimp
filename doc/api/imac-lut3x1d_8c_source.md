---
search:
    keywords: ['imac-lut3x1d.c', 'file']
---

# imac-lut3x1d.c File Reference

**[Go to the documentation of this file.](imac-lut3x1d_8c.md)**
Source: `src/core/imac-lut3x1d.c`

    
    
    
    
    
    
      
    
    
    
```cpp
#include "imac-lut3x1d.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor */
int lut3x1d_new(ImacLut3x1d* lut3x1d) {
    lut3x1d->channelSize = 256;
    lut3x1d->dataR = (int*) malloc(lut3x1d->channelSize * sizeof(int));
    lut3x1d->dataG = (int*) malloc(lut3x1d->channelSize * sizeof(int));
    lut3x1d->dataB = (int*) malloc(lut3x1d->channelSize * sizeof(int));
    if (lut3x1d->dataR == NULL) {
        printf("lut3x1d_new: DataR is null");
        exit(EXIT_FAILURE);
    }
    if (lut3x1d->dataG == NULL) {
        printf("lut3x1d_new: DataG is null");
        exit(EXIT_FAILURE);
    }
    if (lut3x1d->dataB == NULL) {
        printf("lut3x1d_new: DataB is null");
        exit(EXIT_FAILURE);
    }

    // Init to no-effect lut3x1d
    for (unsigned int i = 0; i < lut3x1d->channelSize; i++) {
        lut3x1d_set(lut3x1d, i, i, red);
        lut3x1d_set(lut3x1d, i, i, green);
        lut3x1d_set(lut3x1d, i, i, blue);
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
void lut3x1d_set(ImacLut3x1d* lut3x1d, unsigned int index, int value, enum img_Channel c) {
    if (index >= lut3x1d->channelSize) {
        printf("Error lut3x1d_getIndex: index superior to lut3x1d channel size\n");
        DEBUG_BREAK;
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
            DEBUG_BREAK;
            exit(EXIT_FAILURE);
    }
}

void lut3x1d_apply(ImacLut3x1d* lut3x1d, ImacImg* img) {
    double avgBrightness = 0;
    int brightnessR = 0;
    int brightnessG = 0;
    int brightnessB = 0;

    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            brightnessR = img_getPixelChannel(img, x, y, red);
            brightnessG = img_getPixelChannel(img, x, y, green);
            brightnessB = img_getPixelChannel(img, x, y, blue);

            // Is it a gamma to linear ratio ? If so use a function to say it
            avgBrightness = 0.3 * brightnessR + 0.59 * brightnessG + 0.11 * brightnessB;

            brightnessR = lut3x1d_get(lut3x1d, (int) avgBrightness, red);
            img_setPixelChannel(img, x, y, brightnessR, red);

            brightnessG = lut3x1d_get(lut3x1d, (int) avgBrightness, green);
            img_setPixelChannel(img, x, y, brightnessG, green);

            brightnessB = lut3x1d_get(lut3x1d, (int) avgBrightness, blue);
            img_setPixelChannel(img, x, y, brightnessB, blue);
        }
    }
}

/* Getters */
int lut3x1d_get(ImacLut3x1d* lut3x1d, unsigned int index, enum img_Channel c) {
    if (index >= lut3x1d->channelSize) {
        printf("Error lut3x1d_get: index superior to lut3x1d size\n");
        DEBUG_BREAK;
        return(EXIT_FAILURE);
    }

    switch(c) {
        case red: return lut3x1d->dataR[index];
        case green: return lut3x1d->dataG[index];
        case blue: return lut3x1d->dataB[index];
        default:
            printf("Error lut3x1d_get: Unknown color\n");
            DEBUG_BREAK;
            exit(EXIT_FAILURE);
    }
}
```


    
  
