---
search:
    keywords: ['imac-lut3x1d.h', 'ImacLut3x1d', 'ImacLut3x1d', 'lut3d_new', 'lut3d_delete', 'lut3d_set', 'lut3d_apply', 'lut3d_get', 'lut3d_print']
---

# file imac-lut3x1d.h

**[Go to the source code of this file.](imac-lut3x1d_8h_source.md)**
3x 1D look up table handler 
## Classes

|Type|Name|
|-----|-----|
|struct|[**ImacLut3x1d**](struct_imac_lut3x1d.md)|


## Typedefs

|Type|Name|
|-----|-----|
|typedef struct **[ImacLut3x1d](struct_imac_lut3x1d.md)**|[**ImacLut3x1d**](imac-lut3x1d_8h.md#1a471b73ce8030c51b1c9930f92a9dae5e)|


## Functions

|Type|Name|
|-----|-----|
|int|[**lut3d\_new**](imac-lut3x1d_8h.md#1adb00aa9d058cb2fad935357b256a27af) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3d) <br>Constructor for ImacLut3d. |
|int|[**lut3d\_delete**](imac-lut3x1d_8h.md#1a5230519ea2455e5f2207b0dcbcaec782) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3d) <br>Destructor for ImacLut. |
|void|[**lut3d\_set**](imac-lut3x1d_8h.md#1ae66be29fddf7c5ab9db22205dda25313) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3d, unsigned int index, unsigned char value, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Set the lut3d data with security. |
|void|[**lut3d\_apply**](imac-lut3x1d_8h.md#1a23e25977d11cf659acb802ce9489068f) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3d, **[ImacImg](struct_imac_img.md)** \* img) <br>Apply the lut3d to the image. |
|unsigned char|[**lut3d\_get**](imac-lut3x1d_8h.md#1a8b4c59d8a5734e06eae696755c07e1ac) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3d, unsigned int index, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Access the lut3d data with security. |
|void|[**lut3d\_print**](imac-lut3x1d_8h.md#1a8d3948d962af8703931820856b8ccfbc) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3d) <br>Print the lut3d on debug screen. |


## Typedefs Documentation

### typedef <a id="1a471b73ce8030c51b1c9930f92a9dae5e" href="#1a471b73ce8030c51b1c9930f92a9dae5e">ImacLut3x1d</a>

```cpp
typedef struct ImacLut3x1d  ImacLut3x1d;
```



## Functions Documentation

### function <a id="1adb00aa9d058cb2fad935357b256a27af" href="#1adb00aa9d058cb2fad935357b256a27af">lut3d\_new</a>

```cpp
int imac-lut3x1d.h::lut3d_new (
    ImacLut3x1d * lut3d
)
```

Constructor for ImacLut3d. 



**Note:**

Don't forget to call lut3d\_delete once you are done with the lut3d




**Parameters:**


* **lut3d** 



**Returns:**

EXIT\_SUCCESS or EXIT\_FAILURE 




### function <a id="1a5230519ea2455e5f2207b0dcbcaec782" href="#1a5230519ea2455e5f2207b0dcbcaec782">lut3d\_delete</a>

```cpp
int imac-lut3x1d.h::lut3d_delete (
    ImacLut3x1d * lut3d
)
```

Destructor for ImacLut. 



**Parameters:**


* **lut3d** 



**Returns:**

EXIT\_SUCCESS or EXIT\_FAILURE 




### function <a id="1ae66be29fddf7c5ab9db22205dda25313" href="#1ae66be29fddf7c5ab9db22205dda25313">lut3d\_set</a>

```cpp
void imac-lut3x1d.h::lut3d_set (
    ImacLut3x1d * lut3d,
    unsigned int index,
    unsigned char value,
    enum img_Channel c
)
```

Set the lut3d data with security. 



**Parameters:**


* **lut3d** 
* **index** 
* **value** 
* **channel** 



### function <a id="1a23e25977d11cf659acb802ce9489068f" href="#1a23e25977d11cf659acb802ce9489068f">lut3d\_apply</a>

```cpp
void imac-lut3x1d.h::lut3d_apply (
    ImacLut3x1d * lut3d,
    ImacImg * img
)
```

Apply the lut3d to the image. 



**Parameters:**


* **lut3d** 
* **img** 



**Returns:**

EXIT\_SUCCESS or EXIT\_FAILURE 




### function <a id="1a8b4c59d8a5734e06eae696755c07e1ac" href="#1a8b4c59d8a5734e06eae696755c07e1ac">lut3d\_get</a>

```cpp
unsigned char imac-lut3x1d.h::lut3d_get (
    ImacLut3x1d * lut3d,
    unsigned int index,
    enum img_Channel c
)
```

Access the lut3d data with security. 



**Parameters:**


* **lut3d** 
* **index** 
* **channel** 



**Returns:**

brightness 




### function <a id="1a8d3948d962af8703931820856b8ccfbc" href="#1a8d3948d962af8703931820856b8ccfbc">lut3d\_print</a>

```cpp
void imac-lut3x1d.h::lut3d_print (
    ImacLut3x1d * lut3d
)
```

Print the lut3d on debug screen. 



**Parameters:**


* **lut3d** 





----------------------------------------
The documentation for this class was generated from the following file: `src/core/imac-lut3x1d.h`
