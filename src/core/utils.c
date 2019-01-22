#include "utils.h"
#include "string.h"

/* Input & Outputs */
const char* getFilenameExtension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

char* getDirname(char* path) {
    static const char dot[] = ".";
    char* last_slash;
    /* Find last '/'.  */
    last_slash = path != NULL ? strrchr (path, '/') : NULL;
    if (last_slash != NULL && last_slash != path && last_slash[1] == '\0')
    {
        /* Determine whether all remaining characters are slashes.  */
        char* runp;
        for (runp = last_slash; runp != path; --runp)
            if (runp[-1] != '/')
                break;
    }
    if (last_slash != NULL)
    {
        /* Determine whether all remaining characters are slashes.  */
        char* runp;
        for (runp = last_slash; runp != path; --runp)
            if (runp[-1] != '/')
                break;
        /* Terminate the path.  */
        if (runp == path)
        {
            /* The last slash is the first character in the string.  We have to
               return "/".  As a special case we have to return "//" if there
               are exactly two slashes at the beginning of the string.  See
               XBD 4.10 Path Name Resolution for more information.  */
            if (last_slash == path + 1)
                ++last_slash;
            else
                last_slash = path + 1;
        }
        else
            last_slash = runp;
        last_slash[0] = '\0';
    }
    else
        /* This assignment is ill-designed but the XPG specs require to
           return a string containing "." in any case no directory part is
           found and so a static and constant string is required.  */
        path = (char *) dot;
    return path;
}

/* Maths */
long linearMapping(int value, int start1, int stop1, int start2, int stop2) {
    return (value - start1) * (stop2 - start2) / (stop1 - start1) + start2;
}
