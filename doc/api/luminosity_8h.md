---
search:
    keywords: ['luminosity.h', 'lum_addToImg', 'lum_addToLut', 'lum_dimToImg', 'lum_dimToLut']
---

# file luminosity.h

**[Go to the source code of this file.](luminosity_8h_source.md)**
Change luminosity. 
## Functions

|Type|Name|
|-----|-----|
|void|[**lum\_addToImg**](luminosity_8h.md#1a97fd1e1b02e546bd60feb1f9e6de05d5) (**[ImacImg](struct_imac_img.md)** \* img, unsigned char value) <br>Add value to each color of the image. |
|void|[**lum\_addToLut**](luminosity_8h.md#1a671cdf1a675fee2925215deb01b48b45) (**[ImacLut](struct_imac_lut.md)** \* lut, unsigned char value) <br>Add value to each color of the lut. |
|void|[**lum\_dimToImg**](luminosity_8h.md#1a8291eacb31efd1adb7dbac86c4400886) (**[ImacImg](struct_imac_img.md)** \* img, unsigned char value) <br>Substract value to each color of the image. |
|void|[**lum\_dimToLut**](luminosity_8h.md#1abe7bbf9eb841427f276bd9d0ae238cb9) (**[ImacLut](struct_imac_lut.md)** \* lut, unsigned char value) <br>Substract value to each color of the lut. |


## Functions Documentation

### function <a id="1a97fd1e1b02e546bd60feb1f9e6de05d5" href="#1a97fd1e1b02e546bd60feb1f9e6de05d5">lum\_addToImg</a>

```cpp
void luminosity.h::lum_addToImg (
    ImacImg * img,
    unsigned char value
)
```

Add value to each color of the image. 



**Parameters:**


* **img** 
* **value** 



### function <a id="1a671cdf1a675fee2925215deb01b48b45" href="#1a671cdf1a675fee2925215deb01b48b45">lum\_addToLut</a>

```cpp
void luminosity.h::lum_addToLut (
    ImacLut * lut,
    unsigned char value
)
```

Add value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 



### function <a id="1a8291eacb31efd1adb7dbac86c4400886" href="#1a8291eacb31efd1adb7dbac86c4400886">lum\_dimToImg</a>

```cpp
void luminosity.h::lum_dimToImg (
    ImacImg * img,
    unsigned char value
)
```

Substract value to each color of the image. 



**Parameters:**


* **img** 
* **value** 



### function <a id="1abe7bbf9eb841427f276bd9d0ae238cb9" href="#1abe7bbf9eb841427f276bd9d0ae238cb9">lum\_dimToLut</a>

```cpp
void luminosity.h::lum_dimToLut (
    ImacLut * lut,
    unsigned char value
)
```

Substract value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 





----------------------------------------
The documentation for this class was generated from the following file: `src/luts/luminosity.h`
