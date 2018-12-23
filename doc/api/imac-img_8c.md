---
search:
    keywords: ['imac-img.c', 'getPixelValue', 'setPixelValue', 'getPixel']
---

# file imac-img.c

**[Go to the source code of this file.](imac-img_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|unsigned char|[**getPixelValue**](imac-img_8c.md#1abe430dc04d7aa87969548d1318a9b803) (**[ImacImg](struct_imac_img.md)** \* img, int x, int y, enum **[Color](imac-img_8h.md#1ab87bacfdad76e61b9412d7124be44c1c)** c) <br>Get the pixel value for given color. |
|void|[**setPixelValue**](imac-img_8c.md#1adf193e59f52b23b910222d44937b3bf4) (**[ImacImg](struct_imac_img.md)** \* img, int x, int y, enum **[Color](imac-img_8h.md#1ab87bacfdad76e61b9412d7124be44c1c)** c, unsigned char value) <br>Set the value of the color of a pixel. |
|**[Pixel](struct_pixel.md)**|[**getPixel**](imac-img_8c.md#1a89231b73106fcb3120d5f830194f2fb1) (**[ImacImg](struct_imac_img.md)** \* img, int x, int y) <br>Get a pixel from x y position. Debug-only purpose. |


## Functions Documentation

### function <a id="1abe430dc04d7aa87969548d1318a9b803" href="#1abe430dc04d7aa87969548d1318a9b803">getPixelValue</a>

```cpp
unsigned char imac-img.c::getPixelValue (
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




### function <a id="1adf193e59f52b23b910222d44937b3bf4" href="#1adf193e59f52b23b910222d44937b3bf4">setPixelValue</a>

```cpp
void imac-img.c::setPixelValue (
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



### function <a id="1a89231b73106fcb3120d5f830194f2fb1" href="#1a89231b73106fcb3120d5f830194f2fb1">getPixel</a>

```cpp
Pixel imac-img.c::getPixel (
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






----------------------------------------
The documentation for this class was generated from the following file: `src/imac-img.c`
