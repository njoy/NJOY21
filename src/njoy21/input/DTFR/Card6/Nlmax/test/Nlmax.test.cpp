#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "DTFR nlmax values",
         "[DTFR],[Card6], [Nlmax]"){

  GIVEN( "valid nlmax values" ){
    std::vector<int> validValues{1, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& nlmax : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nlmax) ) );
        REQUIRE( nlmax == argument::extract< 
          DTFR::Card6::Nlmax >( iss ).value );
      }
    } // THEN
  } // GIVEN

  GIVEN( "invalid nlmax values" ){
    std::vector<int> invalidValues{0, -1};

    THEN( "an exception is thrown" ){
      for( auto& nlmax : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(nlmax) ) );
        REQUIRE_THROWS( argument::extract< 
          DTFR::Card6::Nlmax >( iss ) );
      }
    } // THEN
  } // GIVEN
 
  GIVEN( "no input nlmax value" ){
    THEN( "default value is used" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      REQUIRE( 5 == argument::extract< 
        DTFR::Card6::Nlmax >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
