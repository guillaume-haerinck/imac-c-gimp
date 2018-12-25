---
search:
    keywords: ['inversion.h', '_invertLookupTable', 'inv_img', 'inv_lut']
---

# file inversion.h

**[Go to the source code of this file.](inversion_8h_source.md)**
lut for image color inversion 
## Variables

|Type|Name|
|-----|-----|
|static const unsigned char|[**\_invertLookupTable**](inversion_8h.md#1a9d18d9a75a3a0ba191bf55091762bdc5)<br>READONLY PRIVATE look up table for color inversion. |


## Functions

|Type|Name|
|-----|-----|
|void|[**inv\_img**](inversion_8h.md#1aabc938477131b28b96a92bbe80403645) (**[ImacImg](struct_imac_img.md)** \* img) <br>Invert color of the image on procedural calculation. |
|void|[**inv\_lut**](inversion_8h.md#1a8daf68ba1f96da77dfd797a9a2363004) (**[ImacLut](struct_imac_lut.md)** \* lut) <br>Invert color of a LUT. |


## Variables Documentation

### variable <a id="1a9d18d9a75a3a0ba191bf55091762bdc5" href="#1a9d18d9a75a3a0ba191bf55091762bdc5">\_invertLookupTable</a>

```cpp
const unsigned char _invertLookupTable[256];
```

READONLY PRIVATE look up table for color inversion. 


## Functions Documentation

### function <a id="1aabc938477131b28b96a92bbe80403645" href="#1aabc938477131b28b96a92bbe80403645">inv\_img</a>

```cpp
void inversion.h::inv_img (
    ImacImg * img
)
```

Invert color of the image on procedural calculation. 



**Parameters:**


* **img** 



### function <a id="1a8daf68ba1f96da77dfd797a9a2363004" href="#1a8daf68ba1f96da77dfd797a9a2363004">inv\_lut</a>

```cpp
void inversion.h::inv_lut (
    ImacLut * lut
)
```

Invert color of a LUT. 



**Parameters:**


* **lut** 





----------------------------------------
The documentation for this class was generated from the following file: `src/luts/inversion.h`
