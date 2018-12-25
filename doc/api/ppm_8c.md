---
search:
    keywords: ['ppm.c', 'HEADER_LINE_MAX_LENGTH', 'ppm_load', 'ppm_save']
---

# file ppm.c

**[Go to the source code of this file.](ppm_8c_source.md)**
## Defines

|Type|Name|
|-----|-----|
||[**HEADER\_LINE\_MAX\_LENGTH**](ppm_8c.md#1a4f3c10b328bf6da831d837a142e2c960)|


## Functions

|Type|Name|
|-----|-----|
|int|[**ppm\_load**](ppm_8c.md#1acf625deb3c6caa084ead121319ad01b9) (char \* path, **[ImacImg](struct_imac_img.md)** \* img) <br>Load a ppm image file and init the PPMImage pointer with it. |
|int|[**ppm\_save**](ppm_8c.md#1a5967dc2824f47e9eea34426782c60745) (char \* path, **[ImacImg](struct_imac_img.md)** \* img) <br>Save the given ppmImage to a file. |


## Defines Documentation

### define <a id="1a4f3c10b328bf6da831d837a142e2c960" href="#1a4f3c10b328bf6da831d837a142e2c960">HEADER\_LINE\_MAX\_LENGTH</a>

```cpp
define HEADER_LINE_MAX_LENGTH;
```



## Functions Documentation

### function <a id="1acf625deb3c6caa084ead121319ad01b9" href="#1acf625deb3c6caa084ead121319ad01b9">ppm\_load</a>

```cpp
int ppm.c::ppm_load (
    char * path,
    ImacImg * img
)
```

Load a ppm image file and init the PPMImage pointer with it. 



**Note:**

You must call img\_delete once your done with the image




**Parameters:**


* **path** - Relative path to the ppm file 
* **img** 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS. 




### function <a id="1a5967dc2824f47e9eea34426782c60745" href="#1a5967dc2824f47e9eea34426782c60745">ppm\_save</a>

```cpp
int ppm.c::ppm_save (
    char * path,
    ImacImg * img
)
```

Save the given ppmImage to a file. 



**Parameters:**


* **path** - full path with filename 
* **img** - PPMImage to save 
* **format** 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS 






----------------------------------------
The documentation for this class was generated from the following file: `src/image-loaders/ppm.c`
