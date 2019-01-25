---
search:
    keywords: ['contrast.h', 'contrast_addToLut1d', 'contrast_dimToLut1d', 'contrast_sinToLut1d', 'contrast_equalizeToLut1d']
---

# file contrast.h

**[Go to the source code of this file.](contrast_8h_source.md)**
## Functions

|Type|Name|
|-----|-----|
|void|[**contrast\_addToLut1d**](contrast_8h.md#1a591257195793d2a9358c35a2eb024c11) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, int value) <br>Add value to each color of the lut. |
|void|[**contrast\_dimToLut1d**](contrast_8h.md#1aa2a1e01f33e5e29aa73e915bcacc5755) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, int value) <br>Reduce value to each color of the lut. |
|void|[**contrast\_sinToLut1d**](contrast_8h.md#1ade951589424291b686d22b587171b116) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, int value) <br>Add contrast depending on SIN. |
|void|[**contrast\_equalizeToLut1d**](contrast_8h.md#1ab9398291db679ce3758b26df7b21967c) (**[ImacLut1d](struct_imac_lut1d.md)** \* lut, unsigned int histogram) <br>Add contrast depending on Histogram. |


## Functions Documentation

### function <a id="1a591257195793d2a9358c35a2eb024c11" href="#1a591257195793d2a9358c35a2eb024c11">contrast\_addToLut1d</a>

```cpp
void contrast.h::contrast_addToLut1d (
    ImacLut1d * lut,
    int value
)
```

Add value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 



### function <a id="1aa2a1e01f33e5e29aa73e915bcacc5755" href="#1aa2a1e01f33e5e29aa73e915bcacc5755">contrast\_dimToLut1d</a>

```cpp
void contrast.h::contrast_dimToLut1d (
    ImacLut1d * lut,
    int value
)
```

Reduce value to each color of the lut. 



**Parameters:**


* **lut** 
* **value** 



### function <a id="1ade951589424291b686d22b587171b116" href="#1ade951589424291b686d22b587171b116">contrast\_sinToLut1d</a>

```cpp
void contrast.h::contrast_sinToLut1d (
    ImacLut1d * lut,
    int value
)
```

Add contrast depending on SIN. 



**Parameters:**


* **lut** 
* **value** 



### function <a id="1ab9398291db679ce3758b26df7b21967c" href="#1ab9398291db679ce3758b26df7b21967c">contrast\_equalizeToLut1d</a>

```cpp
void contrast.h::contrast_equalizeToLut1d (
    ImacLut1d * lut,
    unsigned int histogram
)
```

Add contrast depending on Histogram. 



**Parameters:**


* **lut** 
* **histogram** 





----------------------------------------
The documentation for this class was generated from the following file: `src/luts/contrast.h`
