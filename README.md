# IMAC Mini Gimp image editor project

## Getting started

### Prerequisites

### Build project

You need a c compiler for your system and cmake installed.
Then use the 'CMakeLists.txt' to create a makefile and build the project.

### Build documentation

You need npm installed, then run `npm install gitbook-cli -g`.
Then run `gitbook serve ./doc`.

## Using the program

It is a command-line program. Here is the full description.
```
minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]
```

And an exemple
```
./minigimp vacances.ppm SEPIA 5 ADDLUM 20 -o super-vacances.ppm
```

## Authors

* **Nicolas Lienart**
* **Guillaume Haerinck**

## Ressources

https://abhijitnathwani.github.io/blog/2017/12/20/First-C-Program-for-Image-Processing

http://adaptiveart.eecs.umich.edu/2011/wp-content/uploads/2011/09/The-pocket-handbook-of-image-processing-algorithms-in-C.pdf

http://adaptiveart.eecs.umich.edu/2011/wp-content/uploads/2011/09/The-pocket-handbook-of-image-processing-algorithms-in-C.pdf

http://home.iitk.ac.in/~rksr/adisl/DIP_Programming_Fundamentals.pdf
