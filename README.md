# IMAC Mini Gimp image editor project

## Getting started

### Build project

You need a c compiler for your system and cmake installed.
Then use the 'CMakeLists.txt' to create a makefile and build the project.

### Build documentation

#### On linux

##### Prerequisite
```
sudo apt-get install npm doxygen doxygen-gui doxygen-doc
```

```
sudo npm install gitbook-cli -g
```

Then you must install doxybook with python3.

##### Update doc

You generate api xml files by running `doxygen`, then with `doxybook -i doc/_xml -o doc/api -s doc/SUMMARY.md -t gitbook
` you transform xml to markdown.
To read, and update markdown in live, run `gitbook serve ./doc`.

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

### Articles

https://embeddedgurus.com/stack-overflow/2010/01/a-tutorial-on-lookup-tables-in-c/

http://paulbourke.net/dataformats/ppm/

https://www.tutorialspoint.com/cprogramming/c_file_io.htm

### Books

https://abhijitnathwani.github.io/blog/2017/12/20/First-C-Program-for-Image-Processing

http://adaptiveart.eecs.umich.edu/2011/wp-content/uploads/2011/09/The-pocket-handbook-of-image-processing-algorithms-in-C.pdf

http://adaptiveart.eecs.umich.edu/2011/wp-content/uploads/2011/09/The-pocket-handbook-of-image-processing-algorithms-in-C.pdf

http://home.iitk.ac.in/~rksr/adisl/DIP_Programming_Fundamentals.pdf

https://www.dreamincode.net/forums/topic/76816-image-processing-tutorial/

### Already existing libraries

https://github.com/ImageMagick/ImageMagick

http://www.graphicsmagick.org/

https://github.com/topics/image-processing?l=c&o=asc&s=forks

