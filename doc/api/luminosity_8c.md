---
search:
    keywords: ['luminosity.c', 'lum_addToImg', 'lum_addToLut1d', 'lum_dimToImg', 'lum_dimToLut1d']
---

# file luminosity.c

**[Go to the source code of this file.](luminosity_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|void|[**lum\_addToImg**](luminosity_8c.md#1a97fd1e1b02e546bd60feb1f9e6de05d5) (**[ImacImg](struct_imac_img.md)** \* img, unsigned char value) <br>Add value to each color of the image. |
|void|[**lum\_addToLut1d**](luminosity_8c.md#1a0cac38eee4826b337990439bcd929a6e) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned char value) <br>Add value to each color of the lut. |
|void|[**lum\_dimToImg**](luminosity_8c.md#1a8291eacb31efd1adb7dbac86c4400886) (**[ImacImg](struct_imac_img.md)** \* img, unsigned char value) <br>Substract value to each color of the image. |
|void|[**lum\_dimToLut1d**](luminosity_8c.md#1abbd8781701827b54f778662fc8e83b4e) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned char value) <br>Substract value to each color of the lut. |


## Functions Documentation

### function <a id="1a97fd1e1b02e546bd60feb1f9e6de05d5" href="#1a97fd1e1b02e546bd60feb1f9e6de05d5">lum\_addToImg</a>

```cpp
void luminosity.c::lum_addToImg (
    ImacImg * img,
    unsigned char value
)
```

Add value to each color of the image. 



**Parameters:**


* **img** 
* **value** 



### function <a id="1a0cac38eee4826b337990439bcd929a6e" href="#1a0cac38eee4826b337990439bcd929a6e">lum\_addToLut1d</a>

```cpp
void luminosity.c::lum_addToLut1d (
    ImacLut1d * lut,
    unsigned char value
)
```

Add value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 



### function <a id="1a8291eacb31efd1adb7dbac86c4400886" href="#1a8291eacb31efd1adb7dbac86c4400886">lum\_dimToImg</a>

```cpp
void luminosity.c::lum_dimToImg (
    ImacImg * img,
    unsigned char value
)
```

Substract value to each color of the image. 



**Parameters:**


* **img** 
* **value** 



### function <a id="1abbd8781701827b54f778662fc8e83b4e" href="#1abbd8781701827b54f778662fc8e83b4e">lum\_dimToLut1d</a>

```cpp
void luminosity.c::lum_dimToLut1d (
    ImacLut1d * lut,
    unsigned char value
)
```

Substract value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 





----------------------------------------
The documentation for this class was generated from the following file: `src/luts/luminosity.c`
