---
search:
    keywords: ['histogram.h', 'file']
---

# histogram.h File Reference

**[Go to the documentation of this file.](histogram_8h.md)**
Source: `src/charts/histogram.h`

    
    
    
    
    
    
      
    
    
    
```cpp
#ifndef MINIGIMP_HISTOGRAM_H
#define MINIGIMP_HISTOGRAM_H

#include "core/imac-img.h"

int hist_rgb(ImacImg* imgToAnalyse, ImacImg* histogram);

int hist_channel(ImacImg* imgToAnalyse, ImacImg* histogram, enum img_Channel c);

static void _printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor);

#endif //MINIGIMP_HISTOGRAM_H
```


    
  
