---
search:
    keywords: ['ImacKernel', 'arraySize', 'matrixSize', 'matrix']
---

# struct ImacKernel

[**Class List**](annotated.md) **>** [**ImacKernel**](struct_imac_kernel.md)


Kernel matrix for convolution operation. [More...](#detailed-description)
## Public Attributes

|Type|Name|
|-----|-----|
|unsigned int|[**arraySize**](struct_imac_kernel.md#1a843746ea29cdf8c55725f192780ff3d8)|
|unsigned int|[**matrixSize**](struct_imac_kernel.md#1a06c6d93be8e35413f70eb87cb3086869)|
|int \*|[**matrix**](struct_imac_kernel.md#1a2ccbdd5ba467faf7b2f7d491427812bd)|


## Detailed Description



**Note:**

Matrix must be a 1 dimensional array, and squared. 



## Public Attributes Documentation

### variable <a id="1a843746ea29cdf8c55725f192780ff3d8" href="#1a843746ea29cdf8c55725f192780ff3d8">arraySize</a>

```cpp
unsigned int arraySize;
```



### variable <a id="1a06c6d93be8e35413f70eb87cb3086869" href="#1a06c6d93be8e35413f70eb87cb3086869">matrixSize</a>

```cpp
unsigned int matrixSize;
```



### variable <a id="1a2ccbdd5ba467faf7b2f7d491427812bd" href="#1a2ccbdd5ba467faf7b2f7d491427812bd">matrix</a>

```cpp
int* matrix;
```





----------------------------------------
The documentation for this class was generated from the following file: `src/core/imac-kernel.h`
