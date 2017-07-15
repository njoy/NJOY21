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
  export NPROC=$(nproc)
else
  export NPROC=$(sysctl -n hw.cpu)
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
rm configuration.txt

repeat 300 echo "Still building..."&
export EKG=$!
       
make VERBOSE=1 -j$NPROC &> compilation.txt
export COMPILATION_FAILURE=$?

if [ $COMPILATION_FAILURE -ne 0 ];
then
  echo "failed while compiling"
  cat compilation.txt  
  exit 1
fi
rm compilation.txt

kill $EKG

ctest --output-on-failure -j$NPROC &> testing.txt
export TEST_FAILURE=$?
if [ $TEST_FAILURE -ne 0 ];
then
    echo "failed while testing"
    cat testing.txt  
    exit 1
fi
rm testing.txt

if $coverage; then
  lcov --directory . \
       --directory ../src \
       --base-directory ../src/njoy21 \
       --capture \
       --output-file coverage.info
  lcov --extract "*njoy21*" \
       --output-file coverage.info
  lcov --remove "*test*" \
       --output-file coverage.info
  bash <(curl -s https://codecov.io/bash) || echo "Codecov did not collect coverage reports"
fi

exit 0
