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
    unsigned int channelSize;
    int* dataR;
    int* dataG;
    int* dataB;
} ImacLut3x1d;

// --------------------- CONSTRUCTOR & DESTRUCTOR

int lut3x1d_new(ImacLut3x1d* lut3x1d);

int lut3x1d_delete(ImacLut3x1d* lut3x1d);

// ---------------------- SETTERS

void lut3x1d_set(ImacLut3x1d* lut3x1d, unsigned int index, int value, enum img_Channel c);

void lut3x1d_apply(ImacLut3x1d* lut3x1d, ImacImg* img);

// ----------------------- GETTERS

int lut3x1d_get(ImacLut3x1d* lut3x1d, unsigned int index, enum img_Channel c);

#endif //MINIGIMP_IMAC_LUT3D_H
```


    
  
