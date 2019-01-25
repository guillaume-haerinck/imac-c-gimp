---
search:
    keywords: ['blur.h', 'blur_imgRecursive', 'blur_vignette', 'blur_imgKernel']
---

# file blur.h

**[Go to the source code of this file.](blur_8h_source.md)**
Convolution based effects for blur. 
## Functions

|Type|Name|
|-----|-----|
|void|[**blur\_imgRecursive**](blur_8h.md#1aeddc95800fd4d81165de55bfba4d3c31) (**[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, int value) <br>Blur the image with a specified level. |
|void|[**blur\_vignette**](blur_8h.md#1a98088fd600893c51f5e4e83a29af746d) (**[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, int value, int posX, int posY) <br>Blur the image with a specified level at a specific position. |
|void|[**blur\_imgKernel**](blur_8h.md#1ad4421bdf7a09dd8f1aa7d58bf35c7da4) (**[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg) <br>Blur the image. |


## Functions Documentation

### function <a id="1aeddc95800fd4d81165de55bfba4d3c31" href="#1aeddc95800fd4d81165de55bfba4d3c31">blur\_imgRecursive</a>

```cpp
void blur.h::blur_imgRecursive (
    ImacImg * img,
    ImacImg * outputImg,
    int value
)
```

Blur the image with a specified level. 



**Parameters:**


* **image** 
* **output** image 
* **blur** intensity 



### function <a id="1a98088fd600893c51f5e4e83a29af746d" href="#1a98088fd600893c51f5e4e83a29af746d">blur\_vignette</a>

```cpp
void blur.h::blur_vignette (
    ImacImg * img,
    ImacImg * outputImg,
    int value,
    int posX,
    int posY
)
```

Blur the image with a specified level at a specific position. 



**Parameters:**


* **image** 
* **output** image 
* **posX** gradient position in image 
* **posY** gradient position in image 
* **blur** intensity 



### function <a id="1ad4421bdf7a09dd8f1aa7d58bf35c7da4" href="#1ad4421bdf7a09dd8f1aa7d58bf35c7da4">blur\_imgKernel</a>

```cpp
void blur.h::blur_imgKernel (
    ImacImg * img,
    ImacImg * outputImg
)
```

Blur the image. 



**Parameters:**


* **image** 
* **output** image 





----------------------------------------
The documentation for this class was generated from the following file: `src/convolution/blur.h`
