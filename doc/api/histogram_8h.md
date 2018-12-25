---
search:
    keywords: ['histogram.h', 'hist_rgb', 'hist_channel', '_printHistogram']
---

# file histogram.h

**[Go to the source code of this file.](histogram_8h_source.md)**
## Functions

|Type|Name|
|-----|-----|
|int|[**hist\_rgb**](histogram_8h.md#1ac105ae4488bceef5a6605623f10127b0) (**[ImacImg](struct_imac_img.md)** \* imgToAnalyse, **[ImacImg](struct_imac_img.md)** \* histogram) <br>Create an average histogram of the image. |
|int|[**hist\_channel**](histogram_8h.md#1aa267d89fe34827b53a308944293861bc) (**[ImacImg](struct_imac_img.md)** \* imgToAnalyse, **[ImacImg](struct_imac_img.md)** \* histogram, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Create an histogram of the image for the selected channel. |
|static void|[**\_printHistogram**](histogram_8h.md#1a4b8da06c1948a05222d0b47a62dc9713) (**[ImacImg](struct_imac_img.md)** \* histogram, unsigned int \* histogramData, unsigned int maxData, unsigned char printColor) <br>Private function used to print histogram data to an image. |


## Functions Documentation

### function <a id="1ac105ae4488bceef5a6605623f10127b0" href="#1ac105ae4488bceef5a6605623f10127b0">hist\_rgb</a>

```cpp
int histogram.h::hist_rgb (
    ImacImg * imgToAnalyse,
    ImacImg * histogram
)
```

Create an average histogram of the image. 



**Parameters:**


* **imgToAnalyse** 
* **histogram** 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS 




### function <a id="1aa267d89fe34827b53a308944293861bc" href="#1aa267d89fe34827b53a308944293861bc">hist\_channel</a>

```cpp
int histogram.h::hist_channel (
    ImacImg * imgToAnalyse,
    ImacImg * histogram,
    enum img_Channel c
)
```

Create an histogram of the image for the selected channel. 



**Parameters:**


* **imgToAnalyse** 
* **histogram** 
* **c** - Color channel 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS 




### function <a id="1a4b8da06c1948a05222d0b47a62dc9713" href="#1a4b8da06c1948a05222d0b47a62dc9713">\_printHistogram</a>

```cpp
static void histogram.h::_printHistogram (
    ImacImg * histogram,
    unsigned int * histogramData,
    unsigned int maxData,
    unsigned char printColor
)
```

Private function used to print histogram data to an image. 



**Parameters:**


* **histogram** 
* **histogramData** 
* **maxData** - Values above will be clamped 
* **printColor** - The color of the printed graph 





----------------------------------------
The documentation for this class was generated from the following file: `src/charts/histogram.h`
