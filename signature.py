#! /usr/bin/env python
"""
"""

import os
import json
import subprocess
import sys
import time

def project_signature():
    invocation = [ "git", "rev-parse", "HEAD" ]
    if os.name == "nt":
        invocation.insert( 0, "powershell" )

    hash_value = subprocess.run( invocation, stdout=subprocess.PIPE ).stdout
    return hash_value.strip().decode("utf-8")

def generate( name = None ):

    project_name = os.path.split( os.getcwd() )[1]
    if name is None:
        name = project_name + str( time.time() )

    git = {}
    git[ project_name ] = project_signature()
    root = os.getcwd()

    if os.path.isdir( "subprojects" ):
        for subproject in os.listdir( "subprojects" ):
            os.chdir(os.path.join("subprojects", subproject))
            git[subproject] = project_signature()
            os.chdir(root)

    with open ( name + ".json", "w" ) as json_file:
        json_file.write( json.dumps( { 'git' : git }, indent=0 ) )

if len(sys.argv) > 1:
    generate( sys.argv[1] )
else:
    generate()
