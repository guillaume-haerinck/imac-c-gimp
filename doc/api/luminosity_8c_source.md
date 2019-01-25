---
search:
    keywords: ['luminosity.c', 'file']
---

# luminosity.c File Reference

**[Go to the documentation of this file.](luminosity_8c.md)**
Source: `src/luts/luminosity.c`

    
    
    
    
      
    
    
    
```cpp
#include "luminosity.h"
#include <stdio.h>

void lum_addToImg(ImacImg* img, int value) {
    int brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            brightness = img_getPixelChannel(img, x, y, red) + value;
            img_setPixelChannel(img, x, y, brightness, red);

            brightness = img_getPixelChannel(img, x, y, green) + value;
            img_setPixelChannel(img, x, y, brightness, green);

            brightness = img_getPixelChannel(img, x, y, blue) + value;
            img_setPixelChannel(img, x, y, brightness, blue);
        }
    }
}

void lum_addToLut1d(ImacLut1d *lut, int value) {
    int brightness = 0;
    for (unsigned int i = 0; i < lut->size; i++) {
        brightness = lut_get(lut, i) + value;
        lut_set(lut, i, brightness);
    }
}

void lum_dimToImg(ImacImg* img, int value) {
    int brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            brightness = img_getPixelChannel(img, x, y, red) - value;
            img_setPixelChannel(img, x, y, brightness, red);

            brightness = img_getPixelChannel(img, x, y, green) - value;
            img_setPixelChannel(img, x, y, brightness, green);

            brightness = img_getPixelChannel(img, x, y, blue) - value;
            img_setPixelChannel(img, x, y, brightness, blue);
        }
    }
}

void lum_dimToLut1d(ImacLut1d *lut, int value) {
    int brightness = 0;
    for (unsigned int i = 0; i < lut->size; i++) {
        brightness = lut_get(lut, i) - value;
        lut_set(lut, i, brightness);
    }
}
```


    
  
