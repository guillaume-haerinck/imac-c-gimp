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

void lum_addToImg(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (unsigned char c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c) + value;
                if (brightness > 255) { brightness = 255; }
                img_setPixelChannel(img, x, y, c, brightness);
            }
        }
    }
}

void lum_addToLut1d(ImacLut1d *lut, unsigned char value) {
    unsigned int brightness = 0;
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = lut->data[i] + value;
        if (brightness > 255) { brightness = 255; }
        lut->data[i] = (unsigned char) brightness;
    }
}

void lum_dimToImg(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (unsigned char c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c) - value;
                if (brightness < 0) { brightness = 0; }
                img_setPixelChannel(img, x, y, brightness, c);
            }
        }
    }
}

void lum_dimToLut1d(ImacLut1d *lut, unsigned char value) {
    int brightness = 0;
    for (unsigned int i = 0; i <= lut->size; i++) {
        brightness = lut_get(lut, i) - value;
        if (brightness < 0) { brightness = 0; }
        lut_set(lut, i, (unsigned char) brightness);
    }
}
```


    
  
