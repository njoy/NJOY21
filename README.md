# NJOY21 --- NJOY for the 21st Century
NJOY21 is the modernized version of NJOY---suitable for computing in the 21st Century. It is based on [NJOY2016](https://njoy.github.io/NJOY21).

## Differences between NJOY21 and NJOY2016
NJOY21 is the modern successor to NJOY2016. It is backwards compatible with NJOY2016---except for a few small changes. 

- NJOY21 writes everything to the screen instead of to the `output` file. This can be changed by using the `-o` and providing a filename when running NJOY21.
- The preferred method for using an input file for NJOY21 is to use the `-i` command-line option. 

    ```
    njoy21 -i U235.inp -o output
    ```
  While you can redirect input and output using `<` and `>` as before, it is preferred to use `-i` and `-o`.

- NJOY21 verifies all the input parameters before performing any processing. This provides a good mechanism to know if your input is valid and provides lots of information if it is not. (Note: we *cannot* ensure that it is correct; that is your responsibility.) The input verification is very strict; if your input does not conform to what is documented in the [manual](https://github.com/njoy/NJOY2016-manual/blob/master/njoy16.pdf), it will not run in NJOY21. 

## NJOY21 Development
NJOY21 is primarily written in modern C++. It consists of many subprojects that are used together to accomplish the entire work that NJOY performs. Initially, NJOY21 is just delegates to NJOY2016; this will ensure backwards compatibility. As the different modules/components of NJOY are modernized, the calls to the Fortran modules (i.e., NJOY2016) will be replaced with calls to the modernized code.

## Installation
Instructions for building and installing NJOY21---as well as any of the subprojects---are found on our (admittedly inadequate) [website](https://njoy.github.io/Build/index.html).

## Manual
The [NJOY2016 manual](https://github.com/njoy/NJOY2016-manual/blob/master/njoy16.pdf) ([download](https://github.com/njoy/NJOY2016-manual/raw/master/njoy16.pdf)) is the current manual for NJOY21. 

## Contributing
NJOY has long benefited from contributors outside of Los Alamos National Laboratory. NJOY21 is released with an Open Source [license](LICENSE) in the hopes of encouraging additional contributions. If you wish to contribute to the NJOY21 project---or any of its subprojects, please reach out to the NJOY team at Los Alamos National Laboratory by sending an email to [njoy@lanl.gov](mailto:njoy@lanl.gov).

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file. 
