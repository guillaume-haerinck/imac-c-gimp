---
search:
    keywords: ['contrast.h', 'contrast_addToLut1d', 'contrast_dimToLut1d']
---

# file contrast.h

**[Go to the source code of this file.](contrast_8h_source.md)**
## Functions

|Type|Name|
|-----|-----|
|void|[**contrast\_addToLut1d**](contrast_8h.md#1a45b6e0f4ad727b2cec9cccdc81b2c2a2) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned char value) <br>Add value to each color of the lut. |
|void|[**contrast\_dimToLut1d**](contrast_8h.md#1aae60a9cb2af13d3fd232c999d7806e26) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned char value) <br>Reduce value to each color of the lut. |


## Functions Documentation

### function <a id="1a45b6e0f4ad727b2cec9cccdc81b2c2a2" href="#1a45b6e0f4ad727b2cec9cccdc81b2c2a2">contrast\_addToLut1d</a>

```cpp
void contrast.h::contrast_addToLut1d (
    ImacLut1d * lut,
    unsigned char value
)
```

Add value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 



### function <a id="1aae60a9cb2af13d3fd232c999d7806e26" href="#1aae60a9cb2af13d3fd232c999d7806e26">contrast\_dimToLut1d</a>

```cpp
void contrast.h::contrast_dimToLut1d (
    ImacLut1d * lut,
    unsigned char value
)
```

Reduce value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 





----------------------------------------
The documentation for this class was generated from the following file: `src/luts/contrast.h`
