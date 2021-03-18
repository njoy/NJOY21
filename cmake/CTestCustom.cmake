# These tests are ignored. Remove them from here when that feature of NJOY21
# gets implemented
set(CTEST_CUSTOM_TESTS_IGNORE
   $CTEST_CUSTOM_TESTS_IGNORE
   # Missing capability in RECONR https://github.com/njoy/RECONR/issues/14
   Test30
   # Poor B-10 evaluation
   Test45                        
   # Missing capability in RECONR https://github.com/njoy/RECONR/issues/14
   Test60                        
   )
