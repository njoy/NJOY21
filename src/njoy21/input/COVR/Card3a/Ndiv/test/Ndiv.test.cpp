#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ndiv output values",
  "[COVR], [Card3a], [Ndiv]"){
  GIVEN( "valid inputs for ndiv" ){
    WHEN( "the ndiv value is provided" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto& ndiv : {1, 2, 5} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( ndiv ) ) );
          REQUIRE( ndiv == argument::extract< 
            COVR::Card3a::Ndiv >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no ndiv value given " ){
      iRecordStream<char> iss( std::istringstream( "  /" ) );

      THEN( "default value is substituted in" ){
        REQUIRE( 1 == argument::extract< COVR::Card3a::Ndiv > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "ndiv tapes are out of range" ){
      THEN( "an exception is thrown" ){
        for( auto& ndiv : {-2, -1, 0} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( ndiv ) ) );
          REQUIRE_THROWS( argument::extract< COVR::Card3a::Ndiv>( iss ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

