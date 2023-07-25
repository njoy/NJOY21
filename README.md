![](https://github.com/njoy/NJOY21/workflows/Continuous%20Integration/badge.svg)

# NJOY21

The NJOY Nuclear Data Processing System is a modular computer code designed to read evaluated data in ENDF format, transform the data in various ways, and output the results as libraries designed to be used in various applications. Each module performs a well defined processing task. The modules are essentially independent programs, and they communicate with each other using input and output files, plus a very few common variables.

NJOY21 provides a C++ wrapped version of [NJOY2016](https://github.com/njoy/NJOY2016) with a few additional features (such as an input parser that verifies the NJOY input file before running NJOY2016).

While it was initially intended to modernise NJOY on a module-by-module basis within NJOY21, the modernisation of NJOY has now gone in the direction of a component-based modernisation. As a result, NJOY21 will continue to use NJOY2016 for the foreseeable future. Regular updates will be made to NJOY21, coinciding with the NJOY2016 releases.

## Documentation
The user manual for NJOY21/NJOY2016 can be found here: [NJOY User Manual (pdf)](https://github.com/njoy/NJOY2016-manual/raw/master/njoy16.pdf).

## Release and development versions
For the latest version of NJOY21 and an overview of the latest changes, please see the [Release Notes](ReleaseNotes.md) or the [release](https://github.com/njoy/NJOY2016/releases) page.

## Differences between NJOY21 and NJOY2016
NJOY21 is in essence a wrapper for NJOY2016, and is therefore backwards compatible with NJOY2016. NJOY21 does deviate from the standard NJOY2016 behavious as follows:
- NJOY21 writes everything to the screen instead of to the `output` file. This can be changed by using the `-o` and providing a filename when running NJOY21.
- The preferred method for using an input file for NJOY21 is to use the `-i` command-line option.

    ```
    njoy21 -i U235.inp -o output
    ```
  While you can redirect input and output using `<` and `>` as before, it is preferred to use `-i` and `-o`.

- NJOY21 verifies all the input parameters before performing any processing. This provides a good mechanism to know if your input is valid and provides lots of information if it is not. (Note: we *cannot* ensure that it is correct; that is your responsibility.) The input verification is very strict; if your input does not conform to what is documented in the [manual](https://github.com/njoy/NJOY2016-manual/blob/master/njoy16.pdf), it will not run in NJOY21.

The command-line option `-h` or `--help` provides a little more information as to how to execute NJOY21.

## Installation

### Prerequisites:

The following are the prerequisites for compiling NJOY2016:
  - git
  - cmake 3.15 or higher
  - a C++-17 compliant compiler such as gcc-7 or higher
  - a Fortran 2003 compliant compiler such as gcc-7 or higher
  - Python 3.5 or higher

Note: gcc-11.3 has been known to produce an internal compiler error while compiling NJOY2016, so as a result this specific version of gcc is not supported. Other versions of gcc (version 7 or higher) seem to be capable of compiling NJOY21 and its dependencies.

### Instructions:

To compile the latest NJOY21 version, you can use the following instructions:
```
git clone https://github.com/njoy/NJOY21.git
cd NJOY21
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ../
make -j8
```

The above instructions will produce a release build consisting of dynamic libraries and a dynamically linked executable. When you have already cloned the NJOY21 repository and wish to update to the latest version, you can use the following instructions (inside the build folder):
```
git pull
make -j8
```

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file.
