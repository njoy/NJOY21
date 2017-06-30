#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR jpos values",
  "[DTFR],[Card5], [Jpos]"){

  GIVEN( "valid jpos  values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( int jpos : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( jpos ) ) );
        REQUIRE( jpos == argument::extract< 
          DTFR::Card5::Jpos >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid jpos values" ){
    std::vector<int> invalidValues{-1, -2};

    THEN( "an exception is thrown" ){
      for( int jpos : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( jpos ) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card5::Jpos >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
