---
search:
    keywords: ['inversion.c', 'file']
---

# inversion.c File Reference

**[Go to the documentation of this file.](inversion_8c.md)**
Source: `src/luts/inversion.c`

    
    
    
      
    
    
    
```cpp
#include "inversion.h"

void invert(ImacImg* img) {
    unsigned char brightness = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = (unsigned char) 255 - getPixelValue(img, x, y, c);
                setPixelValue(img, x, y, c, brightness);
            }
        }
    }
}
```


    
  
