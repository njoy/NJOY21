#!/bin/bash
set -x

function repeat {
    while true
    do
        sleep $1
        ${@:2}
    done
}
       
if [ "$TRAVIS_OS_NAME" = "linux" ]; then
  sudo update-alternatives \
    --install /usr/bin/gcc gcc /usr/bin/gcc-6 90 \
    --slave /usr/bin/g++ g++ /usr/bin/g++-6 \
    --slave /usr/bin/gfortran gfortran /usr/bin/gfortran-6 \
    --slave /usr/bin/gcov gcov /usr/bin/gcov-6
  sudo update-alternatives \
    --install /usr/bin/clang clang /usr/bin/clang-3.8 90 \
    --slave /usr/bin/clang++ clang++ /usr/bin/clang++-3.8
  sudo update-alternatives --config gcc
  sudo update-alternatives --config clang
  if [ "$CXX" = "clang++" ]; then
    export PATH=/usr/bin:$PATH
    export CUSTOM='-D link_time_optimization=OFF'
  else
    export CUSTOM='-D link_time_optimization=ON -D CMAKE_AR=/usr/bin/gcc-ar -D CMAKE_NM=/usr/bin/gcc-nm -D CMAKE_RANLIB=/usr/bin/gcc-ranlib'
  fi;
fi

if [ "$build_type" = "coverage" ]; then
  export build_type=DEBUG
  export coverage=true
  export CUSTOM="$CUSTOM -D coverage=ON"
else
  export coverage=false
fi;

mkdir build
cd build
       
cmake -D CMAKE_BUILD_TYPE=$build_type \
      -D static_libraries=$static_libraries \
      -D NJOY21_appended_flags="$appended_flags" \
      $CUSTOM .. &> configuration.txt
export CONFIGURATION_FAILURE=$?

if [ $CONFIGURATION_FAILURE -ne 0 ];
then
  echo "failed while configuring"
  cat configuration.txt
  exit 1
fi

repeat 300 echo "Still building..."&
export EKG = ?!
       
make VERBOSE=1 -j2 &> compilation.txt
export COMPILATION_FAILURE=$?

if [ $COMPILATION_FAILURE -ne 0 ];
then
  echo "failed while compiling"
  cat compilation.txt  
  exit 1
fi

kill $EKG

ctest --output-on-failure -j2 &> testing.txt
export TEST_FAILURE=$?
if [ $TEST_FAILURE -ne 0 ];
then
    echo "failed while testing"
    cat testing.txt  
    exit 1
fi

if $coverage; then
  pip install --user cpp-coveralls &> coverage_upload.txt
  echo "failed while loading coverage information"
  coveralls  --exclude-pattern "/usr/include/.*|.*/CMakeFiles/.*|.*subprojects.*|.*dependencies.*|.*test\.cpp" --root ".." --build-root "." --gcov-options '\-lp' &>> coverage_upload.txt
  if [ $? -ne 0 ];
  then
     echo "failed while coverage report!"
     cat coverage_upload.txt
     exit 1
  fi
fi

exit 0
