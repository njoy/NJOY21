#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nlev output values",
  "[COVR], [Card2z], [Nlev]"){

  GIVEN( "valid input for nlev" ){
    WHEN( "nlev value provided" ){
      std::vector<int> validValues{1, 2, 8, 9};
      THEN( "the returned class has the correct tape value" ){
        for( auto& nlev : validValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nlev ) ) );
          REQUIRE( nlev == argument::extract< 
	    COVR::Card2z::Nlev >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "nlev tapes are out of range" ){
      std::vector<int> invalidValues{0, 10};
      THEN( "an exception is thrown" ){
        for( auto& nlev : invalidValues ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nlev ) ) );
          REQUIRE_THROWS( argument::extract<
            COVR::Card2z::Nlev>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

