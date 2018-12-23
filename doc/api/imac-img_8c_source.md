---
search:
    keywords: ['imac-img.c', 'file']
---

# imac-img.c File Reference

**[Go to the documentation of this file.](imac-img_8c.md)**
Source: `src/imac-img.c`

    
    
    
    
      
    
    
    
```cpp
#include <stdio.h>
#include "imac-img.h"

unsigned char getPixelValue(ImacImg* img, int x, int y, enum Color c) {
    return img->data[y * img->width * (3 + img->transparency) + x * (3 + img->transparency) + c];
}

void setPixelValue(ImacImg* img, int x, int y, enum Color c, unsigned char value) {
    img->data[y * img->width * (3 + img->transparency) + x * (3 + img->transparency) + c] = value;
}

Pixel getPixel(ImacImg* img, int x, int y) {
    if (y > img->height) { printf("Warning ppm_getPixel: y position superior to image height\n"); }
    if (x > img->width) { printf("Warning ppm_getPixel: x position superior to image width\n"); }
    Pixel pix;
    pix.red = img->data[y * img->width * (3 + img->transparency) + x * (3 + img->transparency) + red];
    pix.green = img->data[y * img->width * (3 + img->transparency) + x * (3 + img->transparency) + green];
    pix.blue = img->data[y * img->width * (3 + img->transparency) + x * (3 + img->transparency) + blue];
    if (img->transparency) {
        pix.alpha = img->data[y * img->width * (3 + img->transparency) + x * (3 + img->transparency) + alpha];
    } else {
        pix.alpha = 255;
    }
    return pix;
}
```


    
  
