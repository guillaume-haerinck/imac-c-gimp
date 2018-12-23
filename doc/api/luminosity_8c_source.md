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

void addLuminosity(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    printf("%d\n", value);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = getPixelValue(img, x, y, c) + value;
                if (brightness > 255) { brightness = 255; }
                setPixelValue(img, x, y, c, brightness);
            }
        }
    }
}

void dimLuminosity(ImacImg* img, unsigned char value) {
    unsigned char brightness = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = getPixelValue(img, x, y, c) - value;
                if (brightness < 0) { brightness = 0; }
                setPixelValue(img, x, y, c, brightness);
            }
        }
    }
}
```


    
  
