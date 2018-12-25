---
search:
    keywords: ['main.c', 'file']
---

# main.c File Reference

**[Go to the documentation of this file.](main_8c.md)**
Source: `src/main.c`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
      
    
    
    
```cpp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "imac-img.h"
#include "imac-lut.h"
#include "utils.h"
#include "charts/histogram.h"
#include "image-loaders/ppm.h"
#include "luts/inversion.h"
#include "luts/luminosity.h"

// minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]

int main(int argc, char *argv[]) {
    clock_t start, end;
    double cpuTimeUsed;
    bool bLutUsed = false;
    start = clock();

    if (argc > 0) {
        ImacImg img;
        ImacLut lut;
        lut_new(&lut);
        int imagePathIndex = -1;

        /* Handle filetype */
        if (strcmp("ppm", getFilenameExtension(argv[1])) == 0) {
            ppm_load(argv[1], &img);
        } else {
            printf("Error in main: unknown file extension");
            return EXIT_FAILURE;
        }

        /* Handle args */
        for (int i = 2; i < argc; i++) {
            if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "-histo") == 0) {
                ImacImg histogram;
                img_new(&histogram, 256, 150);
                hist_rgb(&img, &histogram);
                // TODO append histogram to argv[1] name
                ppm_save("./histogram.ppm", &histogram);
                img_delete(&histogram);
            } else if (strcmp(argv[i], "-o") == 0) {
                imagePathIndex = i + 1;
            } else if (strcmp(argv[i], "ADDLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                // TODO
            } else if (strcmp(argv[i], "DIMLUM") == 0) {
                long value = strtol(argv[i + 1], NULL, 10);
                // TODO
            } else if (strcmp(argv[i], "ADDCON") == 0) {
                // printf("Add constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "DIMCON") == 0) {
                // printf("Dim constrast filter power is: %s\n", argv[i + 1]);
            } else if (strcmp(argv[i], "INVERT") == 0) {
                inv_lut(&lut);
                bLutUsed = true;
            } else if (strcmp(argv[i], "SEPIA") == 0) {
                // printf("Sepia filter power is: %s\n", argv[i + 1]);
            }
        }

        /* Save result */
        if (bLutUsed) {
            lut_apply(&lut, &img);
        }
        if (imagePathIndex != -1) {
            ppm_save(argv[imagePathIndex], &img);
        } else {
            ppm_save("output.ppm", &img);
        }

        /* Clean memory */
        lut_delete(&lut);
        img_delete(&img);
    } else {
        printf("No input file provided !\n");
        return EXIT_FAILURE;
    }

    end = clock();
    cpuTimeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU time used (in seconds): %f \n", cpuTimeUsed);
    return EXIT_SUCCESS;
}
```


    
  
