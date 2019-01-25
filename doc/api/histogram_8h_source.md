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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HIST_SIZE 256
#define HIST_HEIGHT 15

void hist_buildHistogram(ImacImg* imgToAnalyse, unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE]);

void hist_getMaxBrightness(unsigned int imgBrightnessSpectrum[rvb+1][HIST_SIZE], unsigned int maxPixelsForBrightness[rvb+1]);

int hist_findMaxIndex(int *histogram, int histSize);

int *hist_initScaledHistogram(int *outputHistogram, int scale);

void hist_printHistValues(int *histogram, int nbOfValues);

void hist_fillScaledHistogram(int *inputHist, int *outputHist, int scale);

void hist_printTerminal(int *histogram1, int *histogram2, int scaleX);

void hist_printHistogram(ImacImg* histogram, unsigned int* histogramData, unsigned int maxData, unsigned char printColor, enum img_Channel);

int hist_rgb(ImacImg* imgToAnalyse, ImacImg* histogram);

int hist_channel(ImacImg* imgToAnalyse, ImacImg* histogram, enum img_Channel c);

#endif //MINIGIMP_HISTOGRAM_H
```


    
  
