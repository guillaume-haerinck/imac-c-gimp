---
search:
    keywords: ['contrast.h', 'file']
---

# contrast.h File Reference

**[Go to the documentation of this file.](contrast_8h.md)**
Source: `src/luts/contrast.h`

    
    
    
    
    
    
    
    
      
    
    
    
```cpp

#ifndef MINIGIMP_CONTRAST_H
#define MINIGIMP_CONTRAST_H

#include "core/imac-img.h"
#include "charts/histogram.h"
#include "core/imac-lut1d.h"

void contrast_addToLut1d(ImacLut1d *lut, int value);

void contrast_dimToLut1d(ImacLut1d *lut, int value);

void contrast_sinToLut1d(ImacLut1d *lut, int value);

void contrast_equalizeToLut1d(ImacLut1d *lut, unsigned int histogram[256]);

#endif //MINIGIMP_CONTRAST_H
```


    
  
