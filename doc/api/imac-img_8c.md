---
search:
    keywords: ['imac-img.c', 'img_new', 'img_delete', 'img_getPixelChannel', 'img_getPixelGrayscale', 'img_setToWhite', 'img_setPixelChannel', 'img_setPixelChannels']
---

# file imac-img.c

**[Go to the source code of this file.](imac-img_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|int|[**img\_new**](imac-img_8c.md#1a9d6e9f6384788fbcdace048c7327209f) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int width, unsigned int height) <br>Constructor for **[ImacImg](struct_imac_img.md)**. |
|int|[**img\_delete**](imac-img_8c.md#1aa00c1131cec1fae13895faba2f1f5cac) (**[ImacImg](struct_imac_img.md)** \* img) <br>Destructor for **[ImacImg](struct_imac_img.md)**. |
|unsigned char|[**img\_getPixelChannel**](imac-img_8c.md#1a19bfc01604a78996551a46ee0a3eb9c3) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int x, unsigned int y, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Get the pixel value for given color. |
|unsigned char|[**img\_getPixelGrayscale**](imac-img_8c.md#1af9fb17f888ac6de641fe82c48ca9bbdb) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int x, unsigned int y) <br>Get the average pixel value. |
|void|[**img\_setToWhite**](imac-img_8c.md#1a8c88589c2eb9c42d7e7916c97f0c20de) (**[ImacImg](struct_imac_img.md)** \* img) <br>Set all the pixels to white. |
|void|[**img\_setPixelChannel**](imac-img_8c.md#1ad25186e851da5eaf7ca0b89456784da2) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int x, unsigned int y, int value, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Set the value of a color of a pixel. |
|void|[**img\_setPixelChannels**](imac-img_8c.md#1a57bc143e9c97536373429aff37c97291) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int x, unsigned int y, int value) <br>Set each colors of the pixel with the value. |


## Functions Documentation

### function <a id="1a9d6e9f6384788fbcdace048c7327209f" href="#1a9d6e9f6384788fbcdace048c7327209f">img\_new</a>

```cpp
int imac-img.c::img_new (
    ImacImg * img,
    unsigned int width,
    unsigned int height
)
```

Constructor for **[ImacImg](struct_imac_img.md)**. 



**Note:**

If you use an image loader, you do not need it 




**Note:**

Don't forget to call img\_delete once you are done with the image 




**Note:**

Width and height are READONLY, because the data array has been allocated with it




**Parameters:**


* **img** 
* **width** 
* **height** 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS 




### function <a id="1aa00c1131cec1fae13895faba2f1f5cac" href="#1aa00c1131cec1fae13895faba2f1f5cac">img\_delete</a>

```cpp
int imac-img.c::img_delete (
    ImacImg * img
)
```

Destructor for **[ImacImg](struct_imac_img.md)**. 



**Parameters:**


* **img** 



**Returns:**






### function <a id="1a19bfc01604a78996551a46ee0a3eb9c3" href="#1a19bfc01604a78996551a46ee0a3eb9c3">img\_getPixelChannel</a>

```cpp
unsigned char imac-img.c::img_getPixelChannel (
    ImacImg * img,
    unsigned int x,
    unsigned int y,
    enum img_Channel c
)
```

Get the pixel value for given color. 



**Note:**

0,0 position is top left corner.




**Parameters:**


* **img** 
* **x** 
* **y** 
* **c** - Channel color enum 



**Returns:**

Brightness value contained between 0 and 255. 




### function <a id="1af9fb17f888ac6de641fe82c48ca9bbdb" href="#1af9fb17f888ac6de641fe82c48ca9bbdb">img\_getPixelGrayscale</a>

```cpp
unsigned char imac-img.c::img_getPixelGrayscale (
    ImacImg * img,
    unsigned int x,
    unsigned int y
)
```

Get the average pixel value. 



**Note:**

0,0 position is top left corner.




**Parameters:**


* **img** 
* **x** 
* **y** 



**Returns:**

Brightness value contained between 0 and 255. 




### function <a id="1a8c88589c2eb9c42d7e7916c97f0c20de" href="#1a8c88589c2eb9c42d7e7916c97f0c20de">img\_setToWhite</a>

```cpp
void imac-img.c::img_setToWhite (
    ImacImg * img
)
```

Set all the pixels to white. 



**Parameters:**


* **img** 



### function <a id="1ad25186e851da5eaf7ca0b89456784da2" href="#1ad25186e851da5eaf7ca0b89456784da2">img\_setPixelChannel</a>

```cpp
void imac-img.c::img_setPixelChannel (
    ImacImg * img,
    unsigned int x,
    unsigned int y,
    int value,
    enum img_Channel c
)
```

Set the value of a color of a pixel. 



**Note:**

0,0 is top left position




**Parameters:**


* **img** 
* **x** 
* **y** 
* **value** 
* **c** - color channel 



### function <a id="1a57bc143e9c97536373429aff37c97291" href="#1a57bc143e9c97536373429aff37c97291">img\_setPixelChannels</a>

```cpp
void imac-img.c::img_setPixelChannels (
    ImacImg * img,
    unsigned int x,
    unsigned int y,
    int value
)
```

Set each colors of the pixel with the value. 



**Note:**

0,0 is top left position




**Parameters:**


* **img** 
* **x** 
* **y** 
* **value** 





----------------------------------------
The documentation for this class was generated from the following file: `src/core/imac-img.c`
