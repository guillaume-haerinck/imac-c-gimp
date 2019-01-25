---
search:
    keywords: ['blur.h', 'file']
---

# blur.h File Reference

**[Go to the documentation of this file.](blur_8h.md)**
Source: `src/convolution/blur.h`

    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp

#ifndef MINIGIMP_BLUR_H
#define MINIGIMP_BLUR_H

#include <math.h>
#include "core/imac-img.h"
#include "core/utils.h"
#include "core/imac-kernel.h"

void blur_imgRecursive(ImacImg *img, ImacImg *outputImg, int value);


void blur_vignette(ImacImg *img, ImacImg *outputImg, int value, int posX, int posY);

void blur_imgKernel(ImacImg* img, ImacImg* outputImg);

#endif //MINIGIMP_BLUR_H
```


    
  
