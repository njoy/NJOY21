# Release Notes&mdash;NJOY21
Given here are some release notes for NJOY21. Each release is made through a formal [Pull Request](https://github.com/njoy/NJOY21/pulls) made on GitHub. There are links in this document that point to each of those Pull Requests, where you can see in great details the changes that were made. Often the Pull Requests are made in response to an [issue](https://github.com/njoy/NJOY21/issues). In such cases, links to those issues are also given.

## [NJOY21 1.0.5](https://github.com/njoy/NJOY21/pull/99)
This update adds to NJOY21 the NJOY2016 capability of >3 IZA values in ACER. This was added in NJOY2016 in [Pull Request #41](https://github.com/njoy/NJOY2016/pull/141). A few updates from lipservice are also included:

- [Removal of dimwits units](https://github.com/njoy/lipservice/pull/10)
- [Adding NZA option to ACER](https://github.com/njoy/lipservice/pull/11), and
- [RECONR to JSON](https://github.com/njoy/lipservice/pull/12).

All of these are included in the this version of NJOY21.
## [NJOY21 1.0.5](https://github.com/njoy/NJOY21/pull/95)
This fixes [Issue \#94](https://github.com/njoy/NJOY21/issues/94) which as caused by [Pull Request \#93](https://github.com/njoy/NJOY21/pull/93).

In [Pull Request#5](https://github.com/njoy/njoy_c_bindings/pull/5) from [njoy_c_bindings](https://github.com/njoy/njoy_c_bindings) the function `njoy_sync_error` was not added. NJOY21 1.0.5 includes [Pull Request#6](https://github.com/njoy/njoy_c_bindings/pull/6) of `njoy_c_bindings` which includes this necessary function.

## [NJOY21 1.0.4](https://github.com/njoy/NJOY21/pull/93)
This version adds the capability to split the output into stderr and stdout. It is facilitated by and depends on [Pull Request#5](https://github.com/njoy/njoy_c_bindings/pull/5) from [njoy_c_bindings](https://github.com/njoy/njoy_c_bindings).

This is a nice little addition because you can see the progress of NJOY21 as it moves through the different NJOY modules. This is also the same behavior as NJOY2016.

## [NJOY21 1.0.3](https://github.com/njoy/NJOY21/pull/92)
Changes in the ENDFtk parser (removing the hopscotch-map dependency) required changes to the build system CMakeLists.txt files. No other code was changed so NJOY21 1.0.3 is equivalent with NJOY21 1.0.2.

## [NJOY21 1.0.2](https://github.com/njoy/NJOY21/pull/87/)
This incorporates the addition of `Ngen8` parameter in MATXSR. This updated occured as a result of [Pull Request \#6](https://github.com/njoy/lipservice/pull/6) from [lipservice](https://github.com/njoy/lipservice).

The manual doesn't state it, but the code allows the parameter `Ngen8` in MATXSR Card1. The updated to lipservice (and thus NJOY21) provides this parameter.

## [NJOY21 1.0.1](https://github.com/njoy/NJOY21/pull/92)
This simply separates the documentation from the code. 
