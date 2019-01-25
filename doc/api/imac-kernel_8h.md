---
search:
    keywords: ['imac-kernel.h', 'ImacKernel', 'ImacKernel', 'kernel_applyGrayscale', 'kernel_applyRgb', 'kernel_get']
---

# file imac-kernel.h

**[Go to the source code of this file.](imac-kernel_8h_source.md)**
## Classes

|Type|Name|
|-----|-----|
|struct|[**ImacKernel**](struct_imac_kernel.md)|


## Typedefs

|Type|Name|
|-----|-----|
|typedef struct **[ImacKernel](struct_imac_kernel.md)**|[**ImacKernel**](imac-kernel_8h.md#1abe62798b9dbf209f31dd31e27c3d7f6a)|


## Functions

|Type|Name|
|-----|-----|
|void|[**kernel\_applyGrayscale**](imac-kernel_8h.md#1a2c2f5ebf76509bb4ed1d66332ab83c2f) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, **[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, float matrixMultiplication) <br>Apply convolution matrix on image. |
|void|[**kernel\_applyRgb**](imac-kernel_8h.md#1aca5ea2decf6bcef9333b435e9d4aa451) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, **[ImacImg](struct_imac_img.md)** \* img, **[ImacImg](struct_imac_img.md)** \* outputImg, float matrixMultiplication) <br>Apply convolution matrix on image. |
|int|[**kernel\_get**](imac-kernel_8h.md#1a4e7321ddb7f98f5a6ce119e2bba16690) (**[ImacKernel](struct_imac_kernel.md)** \* kernel, unsigned int x, unsigned int y) <br>Get the x, y value of the matrix. |


## Typedefs Documentation

### typedef <a id="1abe62798b9dbf209f31dd31e27c3d7f6a" href="#1abe62798b9dbf209f31dd31e27c3d7f6a">ImacKernel</a>

```cpp
typedef struct ImacKernel  ImacKernel;
```



## Functions Documentation

### function <a id="1a2c2f5ebf76509bb4ed1d66332ab83c2f" href="#1a2c2f5ebf76509bb4ed1d66332ab83c2f">kernel\_applyGrayscale</a>

```cpp
void imac-kernel.h::kernel_applyGrayscale (
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
void imac-kernel.h::kernel_applyRgb (
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
int imac-kernel.h::kernel_get (
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
The documentation for this class was generated from the following file: `src/core/imac-kernel.h`
