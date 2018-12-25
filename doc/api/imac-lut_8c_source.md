---
search:
    keywords: ['imac-lut.c', 'file']
---

# imac-lut.c File Reference

**[Go to the documentation of this file.](imac-lut_8c.md)**
Source: `src/imac-lut.c`

    
    
    
    
    
      
    
    
    
```cpp
#include "imac-lut.h"
#include <stdlib.h>
#include <stdio.h>

/* Constructor */
int lut_new(ImacLut* lut) {
    lut->size = 255;
    lut->data = malloc(lut->size * sizeof(unsigned char));
    if (lut->data == NULL) {
        perror("lut_new: Data is null");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

/* Destructor */
int lut_delete(ImacLut* lut) {
    free(lut->data);
    return EXIT_SUCCESS;
}

/* Getters */
int lut_apply(ImacLut* lut, ImacImg* img) {
    unsigned char brightness = 0;
    for (unsigned int y = 0; y < img->height; y++) {
        for (unsigned int x = 0; x < img->width; x++) {
            for (int c = red; c <= blue; c++) {
                brightness = img_getPixelChannel(img, x, y, c);
                brightness = lut->data[brightness];
                img_setPixelChannel(img, x, y, brightness, c);
            }
        }
    }
}
```


    
  
