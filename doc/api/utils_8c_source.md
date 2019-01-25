---
search:
    keywords: ['utils.c', 'file']
---

# utils.c File Reference

**[Go to the documentation of this file.](utils_8c.md)**
Source: `src/core/utils.c`

    
    
    
    
      
    
    
    
```cpp
#include "utils.h"
#include "string.h"

void gui_printLogo() {
    char letterOpenCB[][7+1] = {"   /$$$","  /$$_/"," | $$  "," /$$$  ","|  $$  "," \\ $$  "," |  $$$","  \\___/"};
    char letterCloseCB[][7+1] = {" /$$$  ","|_  $$ ","  | $$ ","  | $$$","  | $$/","  | $$ "," /$$$/ ","|___/  "};
    char letterM[][13+1] = {" /$$      /$$","| $$$    /$$$","| $$$$  /$$$$","| $$ $$/$$ $$","| $$  $$$| $$","| $$\\  $ | $$","| $$ \\/  | $$","|__/     |__/"};
    char letterI[][8+1] = {" /$$$$$$","|_  $$_/","  | $$  ","  | $$  ","  | $$  ","  | $$  "," /$$$$$$","|______/"};
    char letterN[][10+1] = {" /$$   /$$","| $$$ | $$","| $$$$| $$","| $$ $$ $$","| $$  $$$$","| $$\\  $$$","| $$ \\  $$","|__/  \\__/"};
    char letterG[][10+1] = {"  /$$$$$$ "," /$$__  $$","| $$  \\__/","| $$ /$$$$","| $$|_  $$","| $$  \\ $$","|  $$$$$$/"," \\______/ "};
    char letterP[][10+1] = {" /$$$$$$$ ","| $$__  $$","| $$  \\ $$","| $$$$$$$/","| $$____/ ","| $$      ","| $$      ","|__/      "};
    printf("\n");
    for (int i = 0; i < 8; i++) {
        printf(ANSI_COLOR_YELLOW);
        printf("%s", letterOpenCB[i]);
        printf(ANSI_COLOR_GREEN);
        printf("%s", letterM[i]);
        printf("%s", letterI[i]);
        printf("%s", letterN[i]);
        printf("%s", letterI[i]);
        printf(ANSI_COLOR_CYAN);
        printf("%s", letterG[i]);
        printf("%s", letterI[i]);
        printf("%s", letterM[i]);
        printf("%s", letterP[i]);
        printf(ANSI_COLOR_YELLOW);
        printf("%s", letterCloseCB[i]);
        printf("\n");
    }   
    printf(ANSI_COLOR_RESET);
    char developpers[] = "By Guillaume HAERINCK & Nicolas LIENART";
    int padding = (103-strlen(developpers))/2;
