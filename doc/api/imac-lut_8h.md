---
search:
    keywords: ['imac-lut.h', 'ImacLut', 'ImacLut', 'lut_new', 'lut_delete', 'lut_apply']
---

# file imac-lut.h

**[Go to the source code of this file.](imac-lut_8h_source.md)**
Look up table handler. 
## Classes

|Type|Name|
|-----|-----|
|struct|[**ImacLut**](struct_imac_lut.md)|


## Typedefs

|Type|Name|
|-----|-----|
|typedef struct **[ImacLut](struct_imac_lut.md)**|[**ImacLut**](imac-lut_8h.md#1aedb4c012ae7c03b089aa3f8e6b46ecb4)|


## Functions

|Type|Name|
|-----|-----|
|int|[**lut\_new**](imac-lut_8h.md#1a739b3606693a30c8a9ee3227d24437ea) (**[ImacLut](struct_imac_lut.md)** \* lut) <br>Constructor for **[ImacLut](struct_imac_lut.md)**. |
|int|[**lut\_delete**](imac-lut_8h.md#1a0b0a8a224690c57261dc275dad441a4c) (**[ImacLut](struct_imac_lut.md)** \* lut) <br>Destructor for **[ImacLut](struct_imac_lut.md)**. |
|int|[**lut\_apply**](imac-lut_8h.md#1a4e8a6d52ec06cbd67ee39dbf54c857d3) (**[ImacLut](struct_imac_lut.md)** \* lut, **[ImacImg](struct_imac_img.md)** \* img) <br>Apply the lut to the image. |


## Typedefs Documentation

### typedef <a id="1aedb4c012ae7c03b089aa3f8e6b46ecb4" href="#1aedb4c012ae7c03b089aa3f8e6b46ecb4">ImacLut</a>

```cpp
typedef struct ImacLut  ImacLut;
```



## Functions Documentation

### function <a id="1a739b3606693a30c8a9ee3227d24437ea" href="#1a739b3606693a30c8a9ee3227d24437ea">lut\_new</a>

```cpp
int imac-lut.h::lut_new (
    ImacLut * lut
)
```

Constructor for **[ImacLut](struct_imac_lut.md)**. 



**Note:**

Don't forget to call lut\_delete once you are done with the lut




**Parameters:**


* **lut** 



**Returns:**






### function <a id="1a0b0a8a224690c57261dc275dad441a4c" href="#1a0b0a8a224690c57261dc275dad441a4c">lut\_delete</a>

```cpp
int imac-lut.h::lut_delete (
    ImacLut * lut
)
```

Destructor for **[ImacLut](struct_imac_lut.md)**. 



**Parameters:**


* **lut** 



**Returns:**






### function <a id="1a4e8a6d52ec06cbd67ee39dbf54c857d3" href="#1a4e8a6d52ec06cbd67ee39dbf54c857d3">lut\_apply</a>

```cpp
int imac-lut.h::lut_apply (
    ImacLut * lut,
    ImacImg * img
)
```

Apply the lut to the image. 



**Parameters:**


* **lut** 
* **img** 



**Returns:**








----------------------------------------
The documentation for this class was generated from the following file: `src/imac-lut.h`
