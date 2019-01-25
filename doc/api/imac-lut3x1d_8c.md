---
search:
    keywords: ['imac-lut3x1d.c', 'lut3x1d_new', 'lut3x1d_delete', 'lut3x1d_set', 'lut3x1d_apply', 'lut3x1d_get']
---

# file imac-lut3x1d.c

**[Go to the source code of this file.](imac-lut3x1d_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|int|[**lut3x1d\_new**](imac-lut3x1d_8c.md#1af4d8015b438608a0f73cf073dae00494) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3x1d) <br>Constructor for **[ImacLut3x1d](struct_imac_lut3x1d.md)**. |
|int|[**lut3x1d\_delete**](imac-lut3x1d_8c.md#1a8ab197fc249c762b84c012da4799de33) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3x1d) <br>Destructor for ImacLut. |
|void|[**lut3x1d\_set**](imac-lut3x1d_8c.md#1a3a27377555587d566a2df40e79f44f99) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3x1d, unsigned int index, int value, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Set the lut3x1d data with security. |
|void|[**lut3x1d\_apply**](imac-lut3x1d_8c.md#1a26ce0660b7e8ea08a8d78c44028d52df) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3x1d, **[ImacImg](struct_imac_img.md)** \* img) <br>Apply the lut3x1d to the image. |
|int|[**lut3x1d\_get**](imac-lut3x1d_8c.md#1a563e3b7a23d625a3fc20d32ac8a6099c) (**[ImacLut3x1d](struct_imac_lut3x1d.md)** \* lut3x1d, unsigned int index, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Access the lut3x1d data with security. |


## Functions Documentation

### function <a id="1af4d8015b438608a0f73cf073dae00494" href="#1af4d8015b438608a0f73cf073dae00494">lut3x1d\_new</a>

```cpp
int imac-lut3x1d.c::lut3x1d_new (
    ImacLut3x1d * lut3x1d
)
```

Constructor for **[ImacLut3x1d](struct_imac_lut3x1d.md)**. 



**Note:**

Don't forget to call lut3x1d\_delete once you are done with the lut3x1d




**Parameters:**


* **lut3x1d** 



**Returns:**

EXIT\_SUCCESS or EXIT\_FAILURE 




### function <a id="1a8ab197fc249c762b84c012da4799de33" href="#1a8ab197fc249c762b84c012da4799de33">lut3x1d\_delete</a>

```cpp
int imac-lut3x1d.c::lut3x1d_delete (
    ImacLut3x1d * lut3x1d
)
```

Destructor for ImacLut. 



**Parameters:**


* **lut3x1d** 



**Returns:**

EXIT\_SUCCESS or EXIT\_FAILURE 




### function <a id="1a3a27377555587d566a2df40e79f44f99" href="#1a3a27377555587d566a2df40e79f44f99">lut3x1d\_set</a>

```cpp
void imac-lut3x1d.c::lut3x1d_set (
    ImacLut3x1d * lut3x1d,
    unsigned int index,
    int value,
    enum img_Channel c
)
```

Set the lut3x1d data with security. 



**Parameters:**


* **lut3x1d** 
* **index** 
* **value** 
* **channel** 



### function <a id="1a26ce0660b7e8ea08a8d78c44028d52df" href="#1a26ce0660b7e8ea08a8d78c44028d52df">lut3x1d\_apply</a>

```cpp
void imac-lut3x1d.c::lut3x1d_apply (
    ImacLut3x1d * lut3x1d,
    ImacImg * img
)
```

Apply the lut3x1d to the image. 



**Parameters:**


* **lut3x1d** 
* **img** 



**Returns:**

EXIT\_SUCCESS or EXIT\_FAILURE 




### function <a id="1a563e3b7a23d625a3fc20d32ac8a6099c" href="#1a563e3b7a23d625a3fc20d32ac8a6099c">lut3x1d\_get</a>

```cpp
int imac-lut3x1d.c::lut3x1d_get (
    ImacLut3x1d * lut3x1d,
    unsigned int index,
    enum img_Channel c
)
```

Access the lut3x1d data with security. 



**Parameters:**


* **lut3x1d** 
* **index** 
* **channel** 



**Returns:**

brightness 






----------------------------------------
The documentation for this class was generated from the following file: `src/core/imac-lut3x1d.c`
