#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR ifilm values",
  "[DTFR],[Card2], [Ifilm]"){

  GIVEN( "valid ifilm values" ){
    std::vector<int> validValues{0, 1, 2};

    THEN( "the returned class has the correct value" ){
      for( int ifilm : validValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string(ifilm) ) );
        REQUIRE( ifilm == argument::extract< DTFR::Card2::Ifilm >(iss).value );
      }
    } // THEN
  } // GIVEN
  
  GIVEN( "no ifilm value provided" ){
    iRecordStream<char> iss( std::istringstream( " /" ) );
    THEN( "default value is used" ){
      REQUIRE( 0 == argument::extract< DTFR::Card2::Ifilm >( iss ).value );
    } // THEN
  } // GIVEN

  GIVEN( "invalid ifilm values" ){
    std::vector<int> invalidValues{-1, 3};

    THEN( "an exception is thrown" ){
      for( int ifilm : invalidValues ){
        iRecordStream<char> iss( std::istringstream( std::to_string(ifilm) ) );
        REQUIRE_THROWS( argument::extract< DTFR::Card2::Ifilm >( iss ) );
      }
    } // THEN
  } // GIVEN
} // SCENARIO
