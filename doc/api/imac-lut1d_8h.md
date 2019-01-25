---
search:
    keywords: ['imac-lut1d.h', 'ImacLut1d', 'ImacLut1d', 'lut_new', 'lut_delete', 'lut_set', 'lut_applyRgb', 'lut_get']
---

# file imac-lut1d.h

**[Go to the source code of this file.](imac-lut1d_8h_source.md)**
1D Look up table handler 
## Classes

|Type|Name|
|-----|-----|
|struct|[**ImacLut1d**](struct_imac_lut1d.md)|


## Typedefs

|Type|Name|
|-----|-----|
|typedef struct **[ImacLut1d](struct_imac_lut1d.md)**|[**ImacLut1d**](imac-lut1d_8h.md#1ab31cc57809f60bd3714870fe77407a65)|


## Functions

|Type|Name|
|-----|-----|
|int|[**lut\_new**](imac-lut1d_8h.md#1a3b8fea7d63250b4bd1a74d9b3fad8716) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut) <br>Constructor for ImacLut. |
|int|[**lut\_delete**](imac-lut1d_8h.md#1a75b40753aaa4180655818852f580914d) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut) <br>Destructor for ImacLut. |
|void|[**lut\_set**](imac-lut1d_8h.md#1af49a317e4a693701994afc1df3011bd5) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned int index, int value) <br>Set the lut data with security. |
|void|[**lut\_applyRgb**](imac-lut1d_8h.md#1a5f5379eca99ef1ab8f5ade07033f9f4c) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, **[ImacImg](struct_imac_img.md)** \* img) <br>Apply the lut to the all the channels of the image. |
|int|[**lut\_get**](imac-lut1d_8h.md#1a0f450a96dfc62448d382c6b277152add) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned int index) <br>Access the lut data with security. |


## Typedefs Documentation

### typedef <a id="1ab31cc57809f60bd3714870fe77407a65" href="#1ab31cc57809f60bd3714870fe77407a65">ImacLut1d</a>

```cpp
typedef struct ImacLut1d  ImacLut1d;
```



## Functions Documentation

### function <a id="1a3b8fea7d63250b4bd1a74d9b3fad8716" href="#1a3b8fea7d63250b4bd1a74d9b3fad8716">lut\_new</a>

```cpp
int imac-lut1d.h::lut_new (
    ImacLut1d * lut
)
```

Constructor for ImacLut. 



**Note:**

Don't forget to call lut\_delete once you are done with the lut




**Parameters:**


* **lut** 



**Returns:**






### function <a id="1a75b40753aaa4180655818852f580914d" href="#1a75b40753aaa4180655818852f580914d">lut\_delete</a>

```cpp
int imac-lut1d.h::lut_delete (
    ImacLut1d * lut
)
```

Destructor for ImacLut. 



**Parameters:**


* **lut** 



**Returns:**






### function <a id="1af49a317e4a693701994afc1df3011bd5" href="#1af49a317e4a693701994afc1df3011bd5">lut\_set</a>

```cpp
void imac-lut1d.h::lut_set (
    ImacLut1d * lut,
    unsigned int index,
    int value
)
```

Set the lut data with security. 



**Parameters:**


* **lut** 
* **index** 
* **value** 



**Returns:**

brightness 




### function <a id="1a5f5379eca99ef1ab8f5ade07033f9f4c" href="#1a5f5379eca99ef1ab8f5ade07033f9f4c">lut\_applyRgb</a>

```cpp
void imac-lut1d.h::lut_applyRgb (
    ImacLut1d * lut,
    ImacImg * img
)
```

Apply the lut to the all the channels of the image. 



**Parameters:**


* **lut** 
* **img** 



### function <a id="1a0f450a96dfc62448d382c6b277152add" href="#1a0f450a96dfc62448d382c6b277152add">lut\_get</a>

```cpp
int imac-lut1d.h::lut_get (
    ImacLut1d * lut,
    unsigned int index
)
```

Access the lut data with security. 



**Parameters:**


* **lut** 
* **index** 



**Returns:**

brightness 






----------------------------------------
The documentation for this class was generated from the following file: `src/core/imac-lut1d.h`
