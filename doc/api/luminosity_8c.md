---
search:
    keywords: ['luminosity.c', 'lum_addToImg', 'lum_addToLut1d', 'lum_dimToImg', 'lum_dimToLut1d']
---

# file luminosity.c

**[Go to the source code of this file.](luminosity_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|void|[**lum\_addToImg**](luminosity_8c.md#1a0c7a3912d85a68443e43483b68971d7e) (**[ImacImg](struct_imac_img.md)** \* img, int value) <br>Add value to each color of the image. |
|void|[**lum\_addToLut1d**](luminosity_8c.md#1a6e31cd3b40471fe08c7f803898086ceb) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, int value) <br>Add value to each color of the lut. |
|void|[**lum\_dimToImg**](luminosity_8c.md#1a5b7dbf31fe5740d6dd69a1a845f16c38) (**[ImacImg](struct_imac_img.md)** \* img, int value) <br>Substract value to each color of the image. |
|void|[**lum\_dimToLut1d**](luminosity_8c.md#1a6010503968eb42b6a68d2d78d191d6aa) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, int value) <br>Substract value to each color of the lut. |


## Functions Documentation

### function <a id="1a0c7a3912d85a68443e43483b68971d7e" href="#1a0c7a3912d85a68443e43483b68971d7e">lum\_addToImg</a>

```cpp
void luminosity.c::lum_addToImg (
    ImacImg * img,
    int value
)
```

Add value to each color of the image. 



**Parameters:**


* **img** 
* **value** 



### function <a id="1a6e31cd3b40471fe08c7f803898086ceb" href="#1a6e31cd3b40471fe08c7f803898086ceb">lum\_addToLut1d</a>

```cpp
void luminosity.c::lum_addToLut1d (
    ImacLut1d * lut,
    int value
)
```

Add value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 



### function <a id="1a5b7dbf31fe5740d6dd69a1a845f16c38" href="#1a5b7dbf31fe5740d6dd69a1a845f16c38">lum\_dimToImg</a>

```cpp
void luminosity.c::lum_dimToImg (
    ImacImg * img,
    int value
)
```

Substract value to each color of the image. 



**Parameters:**


* **img** 
* **value** 



### function <a id="1a6010503968eb42b6a68d2d78d191d6aa" href="#1a6010503968eb42b6a68d2d78d191d6aa">lum\_dimToLut1d</a>

```cpp
void luminosity.c::lum_dimToLut1d (
    ImacLut1d * lut,
    int value
)
```

Substract value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 





----------------------------------------
The documentation for this class was generated from the following file: `src/luts/luminosity.c`
