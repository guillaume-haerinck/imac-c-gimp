---
search:
    keywords: ['imac-lut3x1d.h', 'file']
---

# imac-lut3x1d.h File Reference

**[Go to the documentation of this file.](imac-lut3x1d_8h.md)**
Source: `src/core/imac-lut3x1d.h`

    
    
    
    
    
    
    
    
      
      
    
    
    
```cpp

#ifndef MINIGIMP_IMAC_LUT3D_H
#define MINIGIMP_IMAC_LUT3D_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

typedef struct ImacLut3x1d {
    unsigned char channelSize;
    unsigned char* dataR;
    unsigned char* dataG;
    unsigned char* dataB;
} ImacLut3x1d;

// --------------------- CONSTRUCTOR & DESTRUCTOR

int lut3d_new(ImacLut3x1d* lut3d);

int lut3d_delete(ImacLut3x1d* lut3d);

// ---------------------- SETTERS

void lut3d_set(ImacLut3x1d* lut3d, unsigned int index, unsigned char value, enum img_Channel c);

void lut3d_apply(ImacLut3x1d* lut3d, ImacImg* img);

// ----------------------- GETTERS

unsigned char lut3d_get(ImacLut3x1d* lut3d, unsigned int index, enum img_Channel c);

void lut3d_print(ImacLut3x1d* lut3d);

#endif //MINIGIMP_IMAC_LUT3D_H
```


    
  
