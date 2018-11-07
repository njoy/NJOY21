---
layout: page
title: NJOY21—NJOY for the 21st Century
---

NJOY21 is the current production version of NJOY. It is being developed as a modern version of [NJOY2016](https://njoy.github.io/NJOY2016/). NJOY21 is a ground-up rewrite of NJOY2016 and is backwards compatible; that is, input decks that work with NJOY2016, will continue to work with NJOY21. 

## Modernization
Since NJOY21 was being developed from the ground up, we decided to take the opportunity, not to just rewrite NJOY, but to modernize all aspects of it, including:

- How data is read from a file,
- How data is stored in memory,
- How NJOY modules share and transfer data,
- How the NJOY code is tested,
- How NJOY is distributed,
- How NJOY is used or driven,

and many others. NJOY21 is the result of the decisions for the modernization of NJOY. NJOY21 is the version of NJOY that will be developed into the future.

## Short Term 
Initially, NJOY21 will link directly to the Fortran modules of NJOY2016, while providing validity checks of the input values. As functionality is developed in NJOY21 directly, calls to the underlying Fortran routines will be replaced with calls to the new, C++ code. In this way, we have immediate full functionality with new capabilities being introduced as they are available.

All NJOY2016 are currently supported in NJOY21. That is, any input deck that worked properly with NJOY2016, will also work with NJOY21. Note that because of the input verification done with NJOY21, you may find some issues in your Legacy NJOY input decks that you did not know you had. (I did!)

## Goals
We are excited and committed about the future of NJOY21. We have set some [goals](https://njoy.github.io/about/Goals.html) to guide us in this process.

## Motivation
The realization that a major new version of NJOY was needed began with the discussion of new nuclear data formats. NJOY and the ENDF nuclear data format have coexisted for many decades. The process of nuclear data files in NJOY has always been tightly coupled with the [ENDF nuclear data format](http://www.nndc.bnl.gov/csewg/docs/endf-manual.pdf) so any changes to the ENDF format requires changes to NJOY. Adoption of nuclear data formats different from the ENDF format are incompatible with the current NJOY coding and would require significant restructuring of the code base.

In the late 2000’s, an effort was begun to modernize ENDF and resulted in the Generalized Nuclear Database Structure or GNDS. At that time, NJOY developers at Los Alamos National Laboratory recognized that NJOY needed to be modified to be able to handle the forthcoming GNDS format. However, the modification of NJOY to be able to handle GNDS would require a *major* rewrite of NJOY. It was decided to embark on a complete rewrite of the source code.

# Distribution and License
Along with NJOY2016, NJOY21 is being released with an [open-source license](https://github.com/njoy/NJOY21/LICENSE). Also, there are no export control restrictions for NJOY21 as there were for earlier versions. In short, everyone has access to NJOY2016 and NJOY21.

NJOY21 and NJOY2016 are available from our website: [www.njoy21.io](https://www.njoy21.io). For more information on getting NJOY21, please visit [Getting NJOY](https://www.njoy21.io/Build/index.html).
