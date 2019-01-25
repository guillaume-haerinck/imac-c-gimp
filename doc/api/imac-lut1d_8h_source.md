---
search:
    keywords: ['imac-lut1d.h', 'file']
---

# imac-lut1d.h File Reference

**[Go to the documentation of this file.](imac-lut1d_8h.md)**
Source: `src/core/imac-lut1d.h`

    
    
    
    
    
    
    
    
    
    
      
      
    
    
    
```cpp

#ifndef MINIGIMP_IMAC_LUT_H
#define MINIGIMP_IMAC_LUT_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

typedef struct ImacLut1d {
    unsigned int size;
    int* data;
} ImacLut1d;

// --------------------- CONSTRUCTOR & DESTRUCTOR

int lut_new(ImacLut1d* lut);

int lut_delete(ImacLut1d* lut);

// ---------------------- SETTERS

void lut_set(ImacLut1d* lut, unsigned int index, int value);

void lut_applyRgb(ImacLut1d* lut, ImacImg* img);

// ----------------------- GETTERS

int lut_get(ImacLut1d* lut, unsigned int index);

#endif //MINIGIMP_IMAC_LUT_H
```


    
  
