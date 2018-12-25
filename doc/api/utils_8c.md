---
search:
    keywords: ['utils.c', 'getFilenameExtension', 'linearMapping']
---

# file utils.c

**[Go to the source code of this file.](utils_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|const char \*|[**getFilenameExtension**](utils_8c.md#1a7f9c5fd70da52ffcf719d3cd7dfaaee1) (const char \* filename) <br>Get FileExtension (string after last dot) from string input. |
|long|[**linearMapping**](utils_8c.md#1abc960a3069eb518b778464ffa5d6a777) (int value, int start1, int stop1, int start2, int stop2) <br>Map value from interval1 to interval2. |


## Functions Documentation

### function <a id="1a7f9c5fd70da52ffcf719d3cd7dfaaee1" href="#1a7f9c5fd70da52ffcf719d3cd7dfaaee1">getFilenameExtension</a>

```cpp
const char * utils.c::getFilenameExtension (
    const char * filename
)
```

Get FileExtension (string after last dot) from string input. 



**Parameters:**


* **filename** 



**Returns:**

extension 




### function <a id="1abc960a3069eb518b778464ffa5d6a777" href="#1abc960a3069eb518b778464ffa5d6a777">linearMapping</a>

```cpp
long utils.c::linearMapping (
    int value,
    int start1,
    int stop1,
    int start2,
    int stop2
)
```

Map value from interval1 to interval2. 



**Parameters:**


* **value** 
* **start1** 
* **stop1** 
* **start2** 
* **stop2** 



**Returns:**

mappedValue 






----------------------------------------
The documentation for this class was generated from the following file: `src/utils.c`
