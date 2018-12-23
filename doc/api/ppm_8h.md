---
search:
    keywords: ['ppm.h', 'ppm_load', 'ppm_save']
---

# file ppm.h

**[Go to the source code of this file.](ppm_8h_source.md)**
PPM image loader. 
## Functions

|Type|Name|
|-----|-----|
|int|[**ppm\_load**](ppm_8h.md#1acf625deb3c6caa084ead121319ad01b9) (char \* path, **[ImacImg](struct_imac_img.md)** \* img) <br>Load a ppm image file and init the PPMImage pointer with it. |
|int|[**ppm\_save**](ppm_8h.md#1a5967dc2824f47e9eea34426782c60745) (char \* path, **[ImacImg](struct_imac_img.md)** \* img) <br>Save the given ppmImage to a file. |


## Functions Documentation

### function <a id="1acf625deb3c6caa084ead121319ad01b9" href="#1acf625deb3c6caa084ead121319ad01b9">ppm\_load</a>

```cpp
int ppm.h::ppm_load (
    char * path,
    ImacImg * img
)
```

Load a ppm image file and init the PPMImage pointer with it. 



**Note:**

You must free the img data yourself.




**Parameters:**


* **path** - Relative path to the ppm file 
* **img** - Empty pointer with allocated memory 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS. 




### function <a id="1a5967dc2824f47e9eea34426782c60745" href="#1a5967dc2824f47e9eea34426782c60745">ppm\_save</a>

```cpp
int ppm.h::ppm_save (
    char * path,
    ImacImg * img
)
```

Save the given ppmImage to a file. 



**Parameters:**


* **path** - full path with filename 
* **img** - PPMImage to save 



**Returns:**

EXIT\_SUCCESS or EXIT\_FAILURE 






----------------------------------------
The documentation for this class was generated from the following file: `src/image-loaders/ppm.h`
