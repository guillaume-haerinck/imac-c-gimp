---
search:
    keywords: ['imac-lut.h', 'file']
---

# imac-lut.h File Reference

**[Go to the documentation of this file.](imac-lut_8h.md)**
Source: `src/imac-lut.h`

    
    
    
    
    
    
    
    
    
      
      
    
    
    
```cpp

#ifndef MINIGIMP_IMAC_LUT_H
#define MINIGIMP_IMAC_LUT_H

#include "imac-img.h"

// --------------------- STRUCT & ENUMS

typedef struct ImacLut {
    unsigned char size;
    unsigned char* data;
} ImacLut;

// --------------------- CONSTRUCTOR & DESTRUCTOR

int lut_new(ImacLut* lut);

int lut_delete(ImacLut* lut);

// ---------------------- SETTERS
int lut_apply(ImacLut* lut, ImacImg* img);

#endif //MINIGIMP_IMAC_LUT_H
```


    
  
