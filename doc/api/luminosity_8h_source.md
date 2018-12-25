---
search:
    keywords: ['luminosity.h', 'file']
---

# luminosity.h File Reference

**[Go to the documentation of this file.](luminosity_8h.md)**
Source: `src/luts/luminosity.h`

    
    
    
    
    
    
    
      
    
    
    
```cpp

#ifndef MINIGIMP_LUMINOSITY_H
#define MINIGIMP_LUMINOSITY_H

#include "imac-img.h"
#include "imac-lut.h"

void lum_addToImg(ImacImg* img, unsigned char value);

void lum_addToLut(ImacLut* lut, unsigned char value);

void lum_dimToImg(ImacImg* img, unsigned char value);

void lum_dimToLut(ImacLut* lut, unsigned char value);

#endif //MINIGIMP_LUMINOSITY_H
```


    
  
