---
search:
    keywords: ['imac-kernel.h', 'file']
---

# imac-kernel.h File Reference

**[Go to the documentation of this file.](imac-kernel_8h.md)**
Source: `src/core/imac-kernel.h`

    
    
    
    
    
    
    
    
    
      
      
    
    
    
```cpp
#ifndef MINIGIMP_IMAC_KERNEL_H
#define MINIGIMP_IMAC_KERNEL_H

#include "imac-img.h"

typedef struct ImacKernel {
    unsigned int arraySize;
    unsigned int matrixSize;
    int* matrix;
} ImacKernel;

void kernel_applyGrayscale(ImacKernel* kernel, ImacImg* img, ImacImg* outputImg, float matrixMultiplication);

void kernel_applyRgb(ImacKernel* kernel, ImacImg* img, ImacImg* outputImg, float matrixMultiplication);

int kernel_get(ImacKernel* kernel, unsigned int x, unsigned int y);

#endif // MINIGIMP_IMAC_KERNEL_H
```


    
  
