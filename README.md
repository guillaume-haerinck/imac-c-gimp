# IMAC Mini Gimp image editor project

## Getting started

### Build project

You need a C compiler for your system and cmake installed.
Then use the 'CMakeLists.txt' to create a makefile and build the project.

An alternative if you want to avoid using cmake, a makefile for linux is also available. Run `make` to compile the program.
You can also run make clean to purge the directory.

## Using the program

It is a command-line program. Here is the full description.

```
minigimp mon_image.ppm [-h] [-histo] [<code_lut>[_<param1>]*]* [-o image_sortie.ppm]
```

And here is an example
```
./minigimp vacances.ppm SEPIA 5 ADDLUM 20 -o super-vacances.ppm
```

For more details, please read the documentation.

### Read documentation

Documentation is in markdown, generated and served using gitbook.

To get a local version, you need to install gitbook using Node package manager (npm).
```
npm install gitbook-cli -g
```

To read, and update markdown in live, run `gitbook serve doc`.

### Update doxygen reference

#### On linux

##### Prerequisite

```
sudo apt-get install npm doxygen doxygen-gui doxygen-doc
```

Then you must install doxybook with python3.

##### Adding to gitbook

You generate api xml files by running `doxygen`, then with `doxybook -i doc/_xml -o doc/api -s doc/SUMMARY.md -t gitbook` you transform xml to markdown.

## Authors

* **Nicolas Lienart**
* **Guillaume Haerinck**

## TODO

voir utilisation GTK

## Ressources

### Articles

https://affinityspotlight.com/article/1d-vs-3d-luts/

https://embeddedgurus.com/stack-overflow/2010/01/a-tutorial-on-lookup-tables-in-c/

http://paulbourke.net/dataformats/ppm/

https://www.tutorialspoint.com/cprogramming/c_file_io.htm

https://www.mochima.com/articles/LUT/LUT.html

https://docs.opencv.org/2.4/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html

https://www.dfstudios.co.uk/articles/programming/image-programming-algorithms/image-processing-algorithms-part-5-contrast-adjustment/?fbclid=IwAR3ckOxGVc_Y4dCLp3lHU7QkBqBtbxhjTy6jJkn-1UUPMb2L8jiHANva4wc

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

### Third-Party project documentation

https://toolchain.gitbook.com/
https://github.com/matusnovak/doxybook
