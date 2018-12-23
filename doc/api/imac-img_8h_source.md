---
search:
    keywords: ['imac-img.h', 'file']
---

# imac-img.h File Reference

**[Go to the documentation of this file.](imac-img_8h.md)**
Source: `src/imac-img.h`

    
    
    
    
    
    
    
    
    
    
    
      
      
      
    
    
    
```cpp

#ifndef MINIGIMP_IMAC_IMG_H
#define MINIGIMP_IMAC_IMG_H

#include <stdbool.h>

enum ImageFormat {
    P6,
    P5,
    P4,
    P3,
    P2,
    P1
};

typedef struct ImacImg {
    enum ImageFormat format;
    unsigned int width;
    unsigned int height;
    bool transparency;
    unsigned char* data;
} ImacImg;

enum Color {
    red = 0,
    green = 1,
    blue = 2,
    alpha = 3,
};

typedef struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} Pixel;

unsigned char getPixelValue(ImacImg* img, int x, int y, enum Color c);

Pixel getPixel(ImacImg* img, int x, int y);

void setPixelValue(ImacImg* img, int x, int y, enum Color c, unsigned char value);

#endif //MINIGIMP_IMAC_IMG_H
```


    
  
