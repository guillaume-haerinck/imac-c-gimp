---
search:
    keywords: ['inversion.h', '_invertLookupTable', 'inv_img', 'inv_lut1d']
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
|void|[**inv\_lut1d**](inversion_8h.md#1ae7f420cf6ea04be34a05f1b6f54b4bc4) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut) <br>Invert color of a LUT. |


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



### function <a id="1ae7f420cf6ea04be34a05f1b6f54b4bc4" href="#1ae7f420cf6ea04be34a05f1b6f54b4bc4">inv\_lut1d</a>

```cpp
void inversion.h::inv_lut1d (
    ImacLut1d * lut
)
```

Invert color of a LUT. 



**Parameters:**


* **lut** 





----------------------------------------
The documentation for this class was generated from the following file: `src/luts/inversion.h`
