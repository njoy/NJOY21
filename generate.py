#! /usr/bin/env python

import sys

from . import cmake
from . import description

previous = description.deserialize()
keyword_arguments = {}
keywords = [ "include_path", "language_revision" ]

for keyword in keywords:
    if keyword in previous:
        keyword_arguments[keyword] = previous[keyword]

description.generate( previous["name"],
                      previous["target"],
                      previous["language"],
                      previous["version"],
                      previous["is_external_project"],
                      **keyword_arguments )

if sys.argv[1] == 'cmake':
    cmake.generate()
