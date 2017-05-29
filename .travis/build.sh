#!/bin/bash
set -x

if [ "$TRAVIS_OS_NAME" = "linux" ]; then
  sudo update-alternatives \
    --install /usr/bin/gcc gcc /usr/bin/gcc-6 90 \
    --slave /usr/bin/g++ g++ /usr/bin/g++-6 \
    --slave /usr/bin/gfortran gfortran usr/bin/gfortran-6 \
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
    export CUSTOM='-D link_time_optimization=ON'
  fi;
  if [ "$build_type" = "coverage" ]; then
    export build_type=DEBUG
    export coverage=true
    export CUSTOM="$CUSTOM -D coverage=ON"
  else
    export coverage=false
  fi;
fi

mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=$build_type \
      -D static_libraries=$static_libraries \
      -D NJOY21_appended_flags="$appended_flags" \
      $CUSTOM ..
make VERBOSE=1 -j2
export COMPILATION_FAILURE=$?

if [ $COMPILATION_FAILURE -ne 0 ];
then
  exit 1
fi

ctest --output-on-failure -j2
export TEST_FAILURE=$?
if [ $TEST_FAILURE -ne 0 ];
then
    exit 1
fi
if $coverage; then
  pip install --user cpp-coveralls
  echo "loading coverage information"
  coveralls  --exclude-pattern "/usr/include/.*|.*/CMakeFiles/.*|.*subprojects.*|.*dependencies.*|.*test\.cpp" --root ".." --build-root "." --gcov-options '\-lp'
fi
