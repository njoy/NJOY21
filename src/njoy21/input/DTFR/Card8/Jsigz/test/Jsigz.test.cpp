#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR Card8 jsigz input values",
  "[DTFR], [Card8], [Jsigz]"){
  GIVEN( "valid jsigz input values" ){
    std::vector<int> validValues{1, 2, 25};

    THEN( "the returned class has the correct value" ){
      for( auto jsigz : validValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( jsigz )) );
        REQUIRE( jsigz == argument::extract< 
          DTFR::Card8::Jsigz >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid jsigz input values" ){
    std::vector<int> invalidValues{-20, 0};

    THEN( "an exception is thrown" ){
      for( auto jsigz : invalidValues ){
        iRecordStream<char> iss(
          std::istringstream( std::to_string( jsigz )) );
        REQUIRE_THROWS( argument::extract<DTFR::Card8::Jsigz >( iss ) );
      }
    }
  } // GIVEN

  GIVEN( "No jsigz input value" ){
    THEN( "the default value is used" ){
      iRecordStream<char> iss(
        std::istringstream( " /" ) );
      REQUIRE( 1 == argument::extract< DTFR::Card8::Jsigz >( iss ).value );
    } // THEN
  } // GIVEN  
} // SCENARIO
