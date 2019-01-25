---
search:
    keywords: ['imac-img.h', 'file']
---

# imac-img.h File Reference

**[Go to the documentation of this file.](imac-img_8h.md)**
Source: `src/core/imac-img.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
      
      
      
    
    
    
```cpp

#ifndef MINIGIMP_IMAC_IMG_H
#define MINIGIMP_IMAC_IMG_H

#include <stdbool.h>

// ------------------------------------- STRUCTS & ENUMS

enum img_Channel {
    red = 0,
    green = 1,
    blue = 2,
    rvb = 3,
};

enum img_Format {
    P6,
    P5,
    P4,
    P3,
    P2,
    P1
};

typedef struct ImacImg {
    unsigned int width;
    unsigned int height;
    unsigned char* data;
} ImacImg;

// ------------------------------------- CONSTRUCTOR & DESTRUCTOR

int img_new(ImacImg* img, unsigned int width, unsigned int height);

int img_delete(ImacImg* img);

// ------------------------------------- GETTERS

unsigned char img_getPixelChannel(ImacImg* img, unsigned int x, unsigned int y, enum img_Channel c);

unsigned char img_getPixelGrayscale(ImacImg* img, unsigned int x, unsigned int y);

// ------------------------------------- SETTERS

void img_setToWhite(ImacImg* img);

void img_setPixelChannel(ImacImg* img, unsigned int x, unsigned int y, int value, enum img_Channel c);

void img_setPixelChannels(ImacImg* img, unsigned  int x, unsigned int y, int value);

#endif //MINIGIMP_IMAC_IMG_H
```


    
  
