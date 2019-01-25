---
search:
    keywords: ['imac-kernel.c', '_getPixelAvgKernelValue', '_getPixelChannelAvgKernelValue', 'kernel_applyGrayscale', 'kernel_applyRgb', 'kernel_get']
---

# file imac-kernel.c

**[Go to the source code of this file.](imac-kernel_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|static int|[**\_getPixelAvgKernelValue**](imac-kernel_8c.md#1a00e9a972ee6fb141dcb125a4641b9078) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, **[ImacImg](struct_imac_img.md)** \* img, unsigned int anchorX, unsigned int anchorY, float matrixMultiplication) |
|static int|[**\_getPixelChannelAvgKernelValue**](imac-kernel_8c.md#1a209e74c92e421be7105c099029e28682) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, **[ImacImg](struct_imac_img.md)** \* img, unsigned int anchorX, unsigned int anchorY, enum **[img\_Channel](imac-img_8h.md#1a415ca2e37928df0e87062550612407a1)** channel, float matrixMultiplication) |
|void|[**kernel\_applyGrayscale**](imac-kernel_8c.md#1a2c2f5ebf76509bb4ed1d66332ab83c2f) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, **[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, float matrixMultiplication) <br>Apply convolution matrix on image. |
|void|[**kernel\_applyRgb**](imac-kernel_8c.md#1aca5ea2decf6bcef9333b435e9d4aa451) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, **[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, float matrixMultiplication) <br>Apply convolution matrix on image. |
|int|[**kernel\_get**](imac-kernel_8c.md#1a4e7321ddb7f98f5a6ce119e2bba16690) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, unsigned int x, unsigned int y) <br>Get the x, y value of the matrix. |


## Functions Documentation

### function <a id="1a00e9a972ee6fb141dcb125a4641b9078" href="#1a00e9a972ee6fb141dcb125a4641b9078">\_getPixelAvgKernelValue</a>

```cpp
static int imac-kernel.c::_getPixelAvgKernelValue (
    ImacKernel * kernel,
    ImacImg * img,
    unsigned int anchorX,
    unsigned int anchorY,
    float matrixMultiplication
)
```



### function <a id="1a209e74c92e421be7105c099029e28682" href="#1a209e74c92e421be7105c099029e28682">\_getPixelChannelAvgKernelValue</a>

```cpp
static int imac-kernel.c::_getPixelChannelAvgKernelValue (
    ImacKernel * kernel,
    ImacImg * img,
    unsigned int anchorX,
    unsigned int anchorY,
    enum img_Channel channel,
    float matrixMultiplication
)
```



### function <a id="1a2c2f5ebf76509bb4ed1d66332ab83c2f" href="#1a2c2f5ebf76509bb4ed1d66332ab83c2f">kernel\_applyGrayscale</a>

```cpp
void imac-kernel.c::kernel_applyGrayscale (
    ImacKernel * kernel,
    ImacImg * img,
    ImacImg * outputImg,
    float matrixMultiplication
)
```

Apply convolution matrix on image. 



**Parameters:**


* **kernel** 
* **img** 



### function <a id="1aca5ea2decf6bcef9333b435e9d4aa451" href="#1aca5ea2decf6bcef9333b435e9d4aa451">kernel\_applyRgb</a>

```cpp
void imac-kernel.c::kernel_applyRgb (
    ImacKernel * kernel,
    ImacImg * img,
    ImacImg * outputImg,
    float matrixMultiplication
)
```

Apply convolution matrix on image. 



**Parameters:**


* **kernel** 
* **img** 



### function <a id="1a4e7321ddb7f98f5a6ce119e2bba16690" href="#1a4e7321ddb7f98f5a6ce119e2bba16690">kernel\_get</a>

```cpp
int imac-kernel.c::kernel_get (
    ImacKernel * kernel,
    unsigned int x,
    unsigned int y
)
```

Get the x, y value of the matrix. 



**Note:**

0,0 is top left 




**Parameters:**


* **kernel** 
* **x** 
* **y** 



**Returns:**

value 






----------------------------------------
The documentation for this class was generated from the following file: `src/core/imac-kernel.c`
