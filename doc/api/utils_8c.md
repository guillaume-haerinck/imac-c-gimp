---
search:
    keywords: ['utils.c', 'gui_printLogo', 'gui_progressBar', 'getFilenameExtension', 'getDirname', 'linearMapping']
---

# file utils.c

**[Go to the source code of this file.](utils_8c_source.md)**
## Functions

|Type|Name|
|-----|-----|
|void|[**gui\_printLogo**](utils_8c.md#1ab6bc436c37c273be3898910687e4f755) () |
|void|[**gui\_progressBar**](utils_8c.md#1aa6a0091e9a7e2f546a813aaf52221872) (int currentProgress, int total) |
|const char \*|[**getFilenameExtension**](utils_8c.md#1a7f9c5fd70da52ffcf719d3cd7dfaaee1) (const char \* filename) <br>Get FileExtension (string after last dot) from string input. |
|char \*|[**getDirname**](utils_8c.md#1ac5107ad1c4e44f5e4f6fcb7b887bddf1) (char \* path) <br>Get directory path without filename. |
|long|[**linearMapping**](utils_8c.md#1abc960a3069eb518b778464ffa5d6a777) (int value, int start1, int stop1, int start2, int stop2) <br>Map value from interval1 to interval2. |


## Functions Documentation

### function <a id="1ab6bc436c37c273be3898910687e4f755" href="#1ab6bc436c37c273be3898910687e4f755">gui\_printLogo</a>

```cpp
void utils.c::gui_printLogo ()
```



### function <a id="1aa6a0091e9a7e2f546a813aaf52221872" href="#1aa6a0091e9a7e2f546a813aaf52221872">gui\_progressBar</a>

```cpp
void utils.c::gui_progressBar (
    int currentProgress,
    int total
)
```



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




### function <a id="1ac5107ad1c4e44f5e4f6fcb7b887bddf1" href="#1ac5107ad1c4e44f5e4f6fcb7b887bddf1">getDirname</a>

```cpp
char * utils.c::getDirname (
    char * path
)
```

Get directory path without filename. 



**Note:**

Will change the pointer passed




**Parameters:**


* **path** 



**Returns:**

dirname - no ending '/' 




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
The documentation for this class was generated from the following file: `src/core/utils.c`
