---
search:
    keywords: ['imac-img.c', 'img_new', 'img_delete', 'img_getPixelChannel', 'img_setToWhite', 'img_setPixelChannel', 'img_setPixelChannels']
---

# file imac-img.c

**[Go to the source code of this file.](imac-img_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|int|[**img\_new**](imac-img_8c.md#1a9d6e9f6384788fbcdace048c7327209f) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int width, unsigned int height) <br>Constructor for **[ImacImg](struct_imac_img.md)**. |
|int|[**img\_delete**](imac-img_8c.md#1aa00c1131cec1fae13895faba2f1f5cac) (**[ImacImg](struct_imac_img.md)** \* img) <br>Destructor for **[ImacImg](struct_imac_img.md)**. |
|unsigned char|[**img\_getPixelChannel**](imac-img_8c.md#1a19bfc01604a78996551a46ee0a3eb9c3) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int x, unsigned int y, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Get the pixel value for given color. |
|void|[**img\_setToWhite**](imac-img_8c.md#1a8c88589c2eb9c42d7e7916c97f0c20de) (**[ImacImg](struct_imac_img.md)** \* img) |
|void|[**img\_setPixelChannel**](imac-img_8c.md#1a8f7aa804b06a0df8eafa77e1a4d12805) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int x, unsigned int y, unsigned char value, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Set the value of a color of a pixel. |
|void|[**img\_setPixelChannels**](imac-img_8c.md#1a5b8f1a182c7c694217d09dcdce848308) (**[ImacImg](struct_imac_img.md)** \* img, unsigned int x, unsigned int y, unsigned char value) <br>Set each colors of the pixel with the value. |


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




### function <a id="1a8c88589c2eb9c42d7e7916c97f0c20de" href="#1a8c88589c2eb9c42d7e7916c97f0c20de">img\_setToWhite</a>

```cpp
void imac-img.c::img_setToWhite (
    ImacImg * img
)
```



### function <a id="1a8f7aa804b06a0df8eafa77e1a4d12805" href="#1a8f7aa804b06a0df8eafa77e1a4d12805">img\_setPixelChannel</a>

```cpp
void imac-img.c::img_setPixelChannel (
    ImacImg * img,
    unsigned int x,
    unsigned int y,
    unsigned char value,
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



### function <a id="1a5b8f1a182c7c694217d09dcdce848308" href="#1a5b8f1a182c7c694217d09dcdce848308">img\_setPixelChannels</a>

```cpp
void imac-img.c::img_setPixelChannels (
    ImacImg * img,
    unsigned int x,
    unsigned int y,
    unsigned char value
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
