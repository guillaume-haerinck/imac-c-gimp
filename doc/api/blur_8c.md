---
search:
    keywords: ['blur.c', 'blurKernelMatrix', '_recursiveMatrix', 'blur_vignette', 'blur_imgRecursive', 'blur_imgKernel']
---

# file blur.c

**[Go to the source code of this file.](blur_8c_source.md)**
## Variables

|Type|Name|
|-----|-----|
|static int|[**blurKernelMatrix**](blur_8c.md#1ae8bd20c3d339dd4692af80de2a945b5b)|


## Functions

|Type|Name|
|-----|-----|
|static int|[**\_recursiveMatrix**](blur_8c.md#1a53b2ae7af1d4f199b17ef204f55c01bd) (int n) <br>Calculte the matrix shift value (recursive function) |
|void|[**blur\_vignette**](blur_8c.md#1adab1e4f8477a7692ce10bac3ea180815) (**[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, int value, int posX, int posY) <br>Blur the image with a specified level at a specific position. |
|void|[**blur\_imgRecursive**](blur_8c.md#1aeddc95800fd4d81165de55bfba4d3c31) (**[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, int value) <br>Blur the image with a specified level. |
|void|[**blur\_imgKernel**](blur_8c.md#1ad4421bdf7a09dd8f1aa7d58bf35c7da4) (**[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg) <br>Blur the image. |


## Variables Documentation

### variable <a id="1ae8bd20c3d339dd4692af80de2a945b5b" href="#1ae8bd20c3d339dd4692af80de2a945b5b">blurKernelMatrix</a>

```cpp
int blurKernelMatrix[9];
```



## Functions Documentation

### function <a id="1a53b2ae7af1d4f199b17ef204f55c01bd" href="#1a53b2ae7af1d4f199b17ef204f55c01bd">\_recursiveMatrix</a>

```cpp
static int blur.c::_recursiveMatrix (
    int n
)
```

Calculte the matrix shift value (recursive function) 



**Note:**

Private function 




### function <a id="1adab1e4f8477a7692ce10bac3ea180815" href="#1adab1e4f8477a7692ce10bac3ea180815">blur\_vignette</a>

```cpp
void blur.c::blur_vignette (
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



### function <a id="1aeddc95800fd4d81165de55bfba4d3c31" href="#1aeddc95800fd4d81165de55bfba4d3c31">blur\_imgRecursive</a>

```cpp
void blur.c::blur_imgRecursive (
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



### function <a id="1ad4421bdf7a09dd8f1aa7d58bf35c7da4" href="#1ad4421bdf7a09dd8f1aa7d58bf35c7da4">blur\_imgKernel</a>

```cpp
void blur.c::blur_imgKernel (
    ImacImg * img,
    ImacImg * outputImg
)
```

Blur the image. 



**Parameters:**


* **image** 
* **output** image 





----------------------------------------
The documentation for this class was generated from the following file: `src/convolution/blur.c`
