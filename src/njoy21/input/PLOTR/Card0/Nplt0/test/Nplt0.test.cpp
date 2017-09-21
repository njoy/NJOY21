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
    WHEN( "nplt0 has same absolute value as nplt" ){
      THEN( "an exception is thrown" ){
        {
          iRecordStream<char> iss( std::istringstream("  57") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }{
          iRecordStream<char> iss( std::istringstream(" -57") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }
      }
    }
    WHEN( "nplt0 has values outside the allowable range" ){
      THEN( "an exception is thrown" ){
        {
          iRecordStream<char> iss( std::istringstream("  19") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }{
          iRecordStream<char> iss( std::istringstream(" -19") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }{
          iRecordStream<char> iss( std::istringstream("  100") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }{
          iRecordStream<char> iss( std::istringstream(" -100") );
          REQUIRE_THROWS( argument::extract
                               <PLOTR::Card0::Nplt0 >( iss , nplt ) );
        }
      }
    }
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
