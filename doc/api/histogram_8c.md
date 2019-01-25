---
search:
    keywords: ['histogram.c', 'hist_buildHistogram', 'hist_getMaxBrightness', 'hist_findMaxIndex', 'hist_initScaledHistogram', 'hist_printHistValues', 'hist_fillScaledHistogram', 'hist_printTerminal', 'hist_printHistogram', 'hist_rgb', 'hist_channel']
---

# file histogram.c

**[Go to the source code of this file.](histogram_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|void|[**hist\_buildHistogram**](histogram_8c.md#1ab6d87d3caa3bfce76deaa99a1c907973) (**[ImacImg](struct_imac_img.md)** \* imgToAnalyse, unsigned int imgBrightnessSpectrum) <br>Create an average histogram of the image. |
|void|[**hist\_getMaxBrightness**](histogram_8c.md#1a602822d92208e7235fcf729e3703e695) (unsigned int imgBrightnessSpectrum, unsigned int maxPixelsForBrightness) <br>Find the highest number of similar brightness. |
|int|[**hist\_findMaxIndex**](histogram_8c.md#1a79b4b9e16fbf6ff8b207ebfef9d716a5) (int \* histogram, int histSize) <br>Get max Brightness for a one dimensional array. |
|int \*|[**hist\_initScaledHistogram**](histogram_8c.md#1a794246c2fa95f213746d6b3e78c8078d) (int \* outputHistogram, int scale) <br>Build an appropriate histogram array for terminal printing. |
|void|[**hist\_printHistValues**](histogram_8c.md#1aa30e6d9a0135a2c066a8c92321d814a7) (int \* histogram, int nbOfValues) |
|void|[**hist\_fillScaledHistogram**](histogram_8c.md#1a600e60209c74c3af0c87c5ada28b39ed) (int \* inputHist, int \* outputHist, int scale) <br>Fill scaled histogram array for terminal printing. |
|void|[**hist\_printTerminal**](histogram_8c.md#1a57f8f4f4e17443590242f0bb20ebd0ce) (int \* histogram1, int \* histogram2, int scaleX) <br>Print two histograms in the terminal side by side. |
|void|[**hist\_printHistogram**](histogram_8c.md#1ae749819437144ee6647a7a3a4e4c783f) (**[ImacImg](struct_imac_img.md)** \* histogram, unsigned int \* histogramData, unsigned int maxData, unsigned char printColor, enum img\_Channel) <br>Print histogram data to an image. |
|int|[**hist\_rgb**](histogram_8c.md#1ac105ae4488bceef5a6605623f10127b0) (**[ImacImg](struct_imac_img.md)** \* imgToAnalyse, **[ImacImg](struct_imac_img.md)** \* histogram) <br>Call the functions to build the histogram and put it into an image. |
|int|[**hist\_channel**](histogram_8c.md#1aa267d89fe34827b53a308944293861bc) (**[ImacImg](struct_imac_img.md)** \* imgToAnalyse, **[ImacImg](struct_imac_img.md)** \* histogram, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** c) <br>Create an histogram of the image for the selected channel. |


## Functions Documentation

### function <a id="1ab6d87d3caa3bfce76deaa99a1c907973" href="#1ab6d87d3caa3bfce76deaa99a1c907973">hist\_buildHistogram</a>

```cpp
void histogram.c::hist_buildHistogram (
    ImacImg * imgToAnalyse,
    unsigned int imgBrightnessSpectrum
)
```

Create an average histogram of the image. 



**Parameters:**


* **imgToAnalyse** 
* **imgToAnalyseimgBrightnessSpectrum[4][HIST\_SIZE]** 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS 




### function <a id="1a602822d92208e7235fcf729e3703e695" href="#1a602822d92208e7235fcf729e3703e695">hist\_getMaxBrightness</a>

```cpp
void histogram.c::hist_getMaxBrightness (
    unsigned int imgBrightnessSpectrum,
    unsigned int maxPixelsForBrightness
)
```

Find the highest number of similar brightness. 



**Parameters:**


* **imgToAnalyseimgBrightnessSpectrum[4][HIST\_SIZE]** 
* **maxPixelsForBrightness[4]** 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS 




### function <a id="1a79b4b9e16fbf6ff8b207ebfef9d716a5" href="#1a79b4b9e16fbf6ff8b207ebfef9d716a5">hist\_findMaxIndex</a>

```cpp
int histogram.c::hist_findMaxIndex (
    int * histogram,
    int histSize
)
```

Get max Brightness for a one dimensional array. 



**Parameters:**


* **histogram[size]** 
* **size** 
* **max** brightness value index 



### function <a id="1a794246c2fa95f213746d6b3e78c8078d" href="#1a794246c2fa95f213746d6b3e78c8078d">hist\_initScaledHistogram</a>

```cpp
int * histogram.c::hist_initScaledHistogram (
    int * outputHistogram,
    int scale
)
```

Build an appropriate histogram array for terminal printing. 



**Note:**

You must free the pointer after you are done with it




**Parameters:**


* **outputHistogram[256]** 
* **outputHist[scale]** 
* **pointer** on new array 



### function <a id="1aa30e6d9a0135a2c066a8c92321d814a7" href="#1aa30e6d9a0135a2c066a8c92321d814a7">hist\_printHistValues</a>

```cpp
void histogram.c::hist_printHistValues (
    int * histogram,
    int nbOfValues
)
```



### function <a id="1a600e60209c74c3af0c87c5ada28b39ed" href="#1a600e60209c74c3af0c87c5ada28b39ed">hist\_fillScaledHistogram</a>

```cpp
void histogram.c::hist_fillScaledHistogram (
    int * inputHist,
    int * outputHist,
    int scale
)
```

Fill scaled histogram array for terminal printing. 



**Parameters:**


* **inputHist[256]** 
* **outputHist[scale]** 
* **scale** 



### function <a id="1a57f8f4f4e17443590242f0bb20ebd0ce" href="#1a57f8f4f4e17443590242f0bb20ebd0ce">hist\_printTerminal</a>

```cpp
void histogram.c::hist_printTerminal (
    int * histogram1,
    int * histogram2,
    int scaleX
)
```

Print two histograms in the terminal side by side. 



**Parameters:**


* **histogram1[256]** 
* **histogram2[256]** 
* **scaleX** 



### function <a id="1ae749819437144ee6647a7a3a4e4c783f" href="#1ae749819437144ee6647a7a3a4e4c783f">hist\_printHistogram</a>

```cpp
void histogram.c::hist_printHistogram (
    ImacImg * histogram,
    unsigned int * histogramData,
    unsigned int maxData,
    unsigned char printColor,
    enum img_Channel
)
```

Print histogram data to an image. 



**Parameters:**


* **histogram** 
* **histogramData** 
* **maxData** - Values above will be clamped 
* **printColor** - The color of the printed graph 



### function <a id="1ac105ae4488bceef5a6605623f10127b0" href="#1ac105ae4488bceef5a6605623f10127b0">hist\_rgb</a>

```cpp
int histogram.c::hist_rgb (
    ImacImg * imgToAnalyse,
    ImacImg * histogram
)
```

Call the functions to build the histogram and put it into an image. 



**Parameters:**


* **imgToAnalyse** 
* **histogram** 



**Returns:**

EXIT\_FAILURE or EXIT\_SUCCESS 




### function <a id="1aa267d89fe34827b53a308944293861bc" href="#1aa267d89fe34827b53a308944293861bc">hist\_channel</a>

```cpp
int histogram.c::hist_channel (
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






----------------------------------------
The documentation for this class was generated from the following file: `src/charts/histogram.c`
