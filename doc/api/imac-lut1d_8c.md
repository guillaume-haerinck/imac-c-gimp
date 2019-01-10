---
search:
    keywords: ['imac-lut1d.c', 'lut_new', 'lut_delete', 'lut_set', 'lut_applyRgb', 'lut_get', 'lut_print']
---

# file imac-lut1d.c

**[Go to the source code of this file.](imac-lut1d_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|int|[**lut\_new**](imac-lut1d_8c.md#1a3b8fea7d63250b4bd1a74d9b3fad8716) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut) <br>Constructor for ImacLut. |
|int|[**lut\_delete**](imac-lut1d_8c.md#1a75b40753aaa4180655818852f580914d) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut) <br>Destructor for ImacLut. |
|void|[**lut\_set**](imac-lut1d_8c.md#1a5fd22ba0f57c718e25bef5d2f5d75492) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned int index, unsigned char value) <br>Set the lut data with security. |
|int|[**lut\_applyRgb**](imac-lut1d_8c.md#1a8628891c4dce5cffcf34aa7837a87dcd) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, **[ImacImg](struct_imac_img.md)** \* img) <br>Apply the lut to the all the channels of the image. |
|unsigned char|[**lut\_get**](imac-lut1d_8c.md#1ad1288e72dda052f149045c00ef4cfae2) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned int index) <br>Access the lut data with security. |
|void|[**lut\_print**](imac-lut1d_8c.md#1a1c9acec44b8ca8c0da6da659918f9086) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut) <br>Print the lut on debug screen. |


## Functions Documentation

### function <a id="1a3b8fea7d63250b4bd1a74d9b3fad8716" href="#1a3b8fea7d63250b4bd1a74d9b3fad8716">lut\_new</a>

```cpp
int imac-lut1d.c::lut_new (
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
int imac-lut1d.c::lut_delete (
    ImacLut1d * lut
)
```

Destructor for ImacLut. 



**Parameters:**


* **lut** 



**Returns:**






### function <a id="1a5fd22ba0f57c718e25bef5d2f5d75492" href="#1a5fd22ba0f57c718e25bef5d2f5d75492">lut\_set</a>

```cpp
void imac-lut1d.c::lut_set (
    ImacLut1d * lut,
    unsigned int index,
    unsigned char value
)
```

Set the lut data with security. 



**Parameters:**


* **lut** 
* **index** 
* **value** 



**Returns:**

brightness 




### function <a id="1a8628891c4dce5cffcf34aa7837a87dcd" href="#1a8628891c4dce5cffcf34aa7837a87dcd">lut\_applyRgb</a>

```cpp
int imac-lut1d.c::lut_applyRgb (
    ImacLut1d * lut,
    ImacImg * img
)
```

Apply the lut to the all the channels of the image. 



**Parameters:**


* **lut** 
* **img** 



**Returns:**






### function <a id="1ad1288e72dda052f149045c00ef4cfae2" href="#1ad1288e72dda052f149045c00ef4cfae2">lut\_get</a>

```cpp
unsigned char imac-lut1d.c::lut_get (
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




### function <a id="1a1c9acec44b8ca8c0da6da659918f9086" href="#1a1c9acec44b8ca8c0da6da659918f9086">lut\_print</a>

```cpp
void imac-lut1d.c::lut_print (
    ImacLut1d * lut
)
```

Print the lut on debug screen. 



**Parameters:**


* **lut** 





----------------------------------------
The documentation for this class was generated from the following file: `src/core/imac-lut1d.c`
