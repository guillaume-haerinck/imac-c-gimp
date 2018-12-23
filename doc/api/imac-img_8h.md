---
search:
    keywords: ['imac-img.h', 'ImacImg', 'Pixel', 'ImageFormat', 'Color', 'ImacImg', 'Pixel', 'getPixelValue', 'getPixel', 'setPixelValue']
---

# file imac-img.h

**[Go to the source code of this file.](imac-img_8h_source.md)**
## Classes

|Type|Name|
|-----|-----|
|struct|[**ImacImg**](struct_imac_img.md)|
|struct|[**Pixel**](struct_pixel.md)|


## Enums

|Type|Name|
|-----|-----|
|enum|[**ImageFormat**](imac-img_8h.md#1a22f6b18e781e3c412e7d243f7de6aa5c) { **P6**, **P5**, **P4**, **P3**, **P2**, **P1** } |
|enum|[**Color**](imac-img_8h.md#1ab87bacfdad76e61b9412d7124be44c1c) { **red** = 0, **green** = 1, **blue** = 2, **alpha** = 3 } |


## Typedefs

|Type|Name|
|-----|-----|
|typedef struct **[ImacImg](struct_imac_img.md)**|[**ImacImg**](imac-img_8h.md#1a36f94e74c5010b84b5d637d783bbb750)|
|typedef struct **[Pixel](struct_pixel.md)**|[**Pixel**](imac-img_8h.md#1a852667dea7b3568b4439cfa1609f9684)|


## Functions

|Type|Name|
|-----|-----|
|unsigned char|[**getPixelValue**](imac-img_8h.md#1abe430dc04d7aa87969548d1318a9b803) (**[ImacImg](struct_imac_img.md)** \* img, int x, int y, enum **[Color](imac-img_8h.md#1ab87bacfdad76e61b9412d7124be44c1c)** c) <br>Get the pixel value for given color. |
|**[Pixel](struct_pixel.md)**|[**getPixel**](imac-img_8h.md#1a89231b73106fcb3120d5f830194f2fb1) (**[ImacImg](struct_imac_img.md)** \* img, int x, int y) <br>Get a pixel from x y position. Debug-only purpose. |
|void|[**setPixelValue**](imac-img_8h.md#1adf193e59f52b23b910222d44937b3bf4) (**[ImacImg](struct_imac_img.md)** \* img, int x, int y, enum **[Color](imac-img_8h.md#1ab87bacfdad76e61b9412d7124be44c1c)** c, unsigned char value) <br>Set the value of the color of a pixel. |


## Enums Documentation

### enum <a id="1a22f6b18e781e3c412e7d243f7de6aa5c" href="#1a22f6b18e781e3c412e7d243f7de6aa5c">ImageFormat</a>

```cpp
enum imac-img.h::ImageFormat {
    P6,
    P5,
    P4,
    P3,
    P2,
    P1,
};
```


Image File Format working with this software 

### enum <a id="1ab87bacfdad76e61b9412d7124be44c1c" href="#1ab87bacfdad76e61b9412d7124be44c1c">Color</a>

```cpp
enum imac-img.h::Color {
    red = 0,
    green = 1,
    blue = 2,
    alpha = 3,
};
```



## Typedefs Documentation

### typedef <a id="1a36f94e74c5010b84b5d637d783bbb750" href="#1a36f94e74c5010b84b5d637d783bbb750">ImacImg</a>

```cpp
typedef struct ImacImg  ImacImg;
```



### typedef <a id="1a852667dea7b3568b4439cfa1609f9684" href="#1a852667dea7b3568b4439cfa1609f9684">Pixel</a>

```cpp
typedef struct Pixel  Pixel;
```


Image **[Pixel](struct_pixel.md)** 

## Functions Documentation

### function <a id="1abe430dc04d7aa87969548d1318a9b803" href="#1abe430dc04d7aa87969548d1318a9b803">getPixelValue</a>

```cpp
unsigned char imac-img.h::getPixelValue (
    ImacImg * img,
    int x,
    int y,
    enum Color c
)
```

Get the pixel value for given color. 



**Note:**

0,0 position is top left corner.




**Parameters:**


* **img** 
* **x** 
* **y** 
* **c** 



**Returns:**

Brightness value contained between 0 and 255. 




### function <a id="1a89231b73106fcb3120d5f830194f2fb1" href="#1a89231b73106fcb3120d5f830194f2fb1">getPixel</a>

```cpp
Pixel imac-img.h::getPixel (
    ImacImg * img,
    int x,
    int y
)
```

Get a pixel from x y position. Debug-only purpose. 



**Note:**

0, 0 position is top left corner.




**Parameters:**


* **img** 
* **x** 
* **y** 



**Returns:**

**[Pixel](struct_pixel.md)** with red, green, blue color values (and alpha if available) 




### function <a id="1adf193e59f52b23b910222d44937b3bf4" href="#1adf193e59f52b23b910222d44937b3bf4">setPixelValue</a>

```cpp
void imac-img.h::setPixelValue (
    ImacImg * img,
    int x,
    int y,
    enum Color c,
    unsigned char value
)
```

Set the value of the color of a pixel. 



**Note:**

0,0 is top left position




**Parameters:**


* **img** 
* **x** 
* **y** 
* **c** 
* **value** 





----------------------------------------
The documentation for this class was generated from the following file: `src/imac-img.h`
