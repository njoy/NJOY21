#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 57;
  GIVEN( "valid npend input" ){
    WHEN( "all values are valid" ){
      for( auto npend : {20, 99, 59} ){
        iRecordStream<char> issNpend(
            std::istringstream( std::to_string(npend) ) );
        REQUIRE( npend == argument::extract< GAMINR::Card1::Npend >(
                          issNpend, nendf ).value );
      }
      nendf.value *= -1;
      for( auto npend : {-20, -99, -59} ){
        iRecordStream<char> issNpend(
            std::istringstream( std::to_string(npend) ) );
        REQUIRE( npend == argument::extract< GAMINR::Card1::Npend >(
                          issNpend, nendf).value );
      }
    }
  } // GIVEN
}

SCENARIO( "expected failures" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 57;
  GIVEN( "invalid npend values" ){
    WHEN( "npend has same absolute value as nendf" ){
      THEN( "an exception is thrown" ){
        {
          iRecordStream<char> iss( std::istringstream("  57") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }{
          iRecordStream<char> iss( std::istringstream(" -57") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }
      }
    }
    WHEN( "npend has values outside the allowable range" ){
      THEN( "an exception is thrown" ){
        {
          iRecordStream<char> iss( std::istringstream("  19") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }{
          iRecordStream<char> iss( std::istringstream(" -19") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }{
          iRecordStream<char> iss( std::istringstream("  100") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }{
          iRecordStream<char> iss( std::istringstream(" -100") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }{
          iRecordStream<char> iss( std::istringstream("  0") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }
      }
    }
    WHEN( "npend has a non-integer value or no value at all" ){
      THEN( "an exception is thrown" ){
        {
          iRecordStream<char> iss( std::istringstream(" cat") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }{
          iRecordStream<char> iss( std::istringstream("    ") );
          REQUIRE_THROWS( argument::extract
                               <GAMINR::Card1::Npend >( iss , nendf ) );
        }
      }
    }
  } // GIVEN
}
