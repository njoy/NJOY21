[![Build Status](http://jenkins.njoy21.io:8080/buildStatus/icon?job=NJOY21-Testing-Docker&build=63)](http://jenkins.njoy21.io:8080/view/NJOY21/job/NJOY21-Testing-Docker/63/)

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

The command-line option `-h` or `--help` provides a little more information as to how to execute NJOY21.

## NJOY21 Development
NJOY21 is primarily written in modern C++. It consists of many subprojects that are used together to accomplish the entire work that NJOY performs. Initially, NJOY21 just delegates to NJOY2016; this will ensure backwards compatibility. As the different modules/components of NJOY are modernized, the calls to the Fortran modules (i.e., NJOY2016) will be replaced with calls to the modernized code.

Please refer to the [Release Notes](ReleaseNotes.md) to see what has changed from one version to the next.

## Installation
Instructions for building and installing NJOY21---as well as any of the subprojects---are found on our (admittedly inadequate) [website](https://njoy.github.io/Build/index.html).

## Version
To see the version number for NJOY21, simply execute (after building):
```bash
njoy21 --version
```
NJOY21 roughly follows semantic versioning, where the version number is: `M.m.u` where `M` is the major version number, `m` is the minor version number, and `u` is the update number. These are updated as follows:

1. The major version number `M` is incremented whenever there is a backwards incompatible change. This doesn't happen very often.
2. The minor version is incremented whenever a new capability is added.
3. The update version is incremented whenever a new changed is added to the master (i.e., main or default) branch. This happens most often.

### Signature
NJOY21 has many dependencies that are updated independently of NJOY21. When NJOY21 is configured (using CMake), the latest production version of those dependencies is downloaded and used for compilation.

If you need to build an older version of NJOY21&mdash;including older versions of all dependencies&mdash;you can do using the "signature" of that version of NJOY21. To obtain the signature simply execute:
```bash
njoy21 --signature
```
The signature (a JSON object) will be printed to the screen, which can be then be saved to a file, e.g., `signature.json`. Alternatively, `signature.json` is automatically created whenever NJOY21 is configured. The file is saved in the build directory (typically `bin`) and copied to the install directory during the `make install` phase.

To configure with this signature file, do the following:
```bash
./metaconfigure/fetch_subprojects.py signature.json

# Configure
cmake -D fetched_subprojects=true </path/to/CMakeLists.txt>
make
make test
make install
```
These are similar instructions to when you need to build NJOY21 without access to the internet.

## Manual
The [NJOY2016 manual](https://github.com/njoy/NJOY2016-manual/blob/master/njoy16.pdf) ([download](https://github.com/njoy/NJOY2016-manual/raw/master/njoy16.pdf)) is the current manual for NJOY21.

## Contributing
NJOY has long benefited from contributors outside of Los Alamos National Laboratory. NJOY21 is released with an Open Source [license](LICENSE) in the hopes of encouraging additional contributions. If you wish to contribute to the NJOY21 project---or any of its subprojects, please reach out to the NJOY team at Los Alamos National Laboratory by sending an email to [njoy@lanl.gov](mailto:njoy@lanl.gov).

## LICENSE
This software is copyrighted by Los Alamos National Laboratory and distributed according to the conditions in the accompanying [LICENSE](LICENSE) file.
