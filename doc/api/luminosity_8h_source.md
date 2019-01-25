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

#include "core/imac-img.h"
#include "core/imac-lut1d.h"

void lum_addToImg(ImacImg* img, int value);

void lum_addToLut1d(ImacLut1d *lut, int value);

void lum_dimToImg(ImacImg* img, int value);

void lum_dimToLut1d(ImacLut1d *lut, int value);

#endif //MINIGIMP_LUMINOSITY_H
```


    
  
