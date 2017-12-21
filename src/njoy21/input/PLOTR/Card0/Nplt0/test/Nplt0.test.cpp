#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  Argument< PLOTR::Card0::Nplt > nplt; nplt.value = 57;
  GIVEN( "valid nplt0 input" ){
    WHEN( "all values are valid" ){
      for( auto nplt0: {0, 20, 99, 59} ){
        iRecordStream<char> issNplt0(
            std::istringstream( std::to_string(nplt0) ) );
        REQUIRE( nplt0 == argument::extract< PLOTR::Card0::Nplt0 >(
                          issNplt0, nplt ).value );
      }
      nplt.value *= -1;
      for( auto nplt0 : {-20, -99, -59} ){
        iRecordStream<char> issNplt0(
            std::istringstream( std::to_string(nplt0) ) );
        REQUIRE( nplt0 == argument::extract< PLOTR::Card0::Nplt0 >(
                          issNplt0, nplt ).value );
      }
    }
  } // GIVEN
}

SCENARIO( "expected failures" ){
  Argument< PLOTR::Card0::Nplt > nplt; nplt.value = 57;
  GIVEN( "invalid nplt0 values" ){
    WHEN( "an unallowed value is given" ){
      std::vector<int> invalidVals{-100,-57,-19,19,57,100};

      for( auto val : invalidVals ){

        iRecordStream<char> iss( std::istringstream( std::to_string( val ) ) );
        THEN( "an exception is thrown" ){
          {
            REQUIRE_THROWS( argument::extract
                                         <PLOTR::Card0::Nplt0 >( iss , nplt ) );
          }
        }
      }
    } // WHEN
    WHEN( "nplt0 has a non-integer value or no value at all" ){
      THEN( "an exception is thrown" ){
        {
          iRecordStream<char> iss( std::istringstream(" cat") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }{
          iRecordStream<char> iss( std::istringstream("    ") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }
      }
    }
  } // GIVEN
}
