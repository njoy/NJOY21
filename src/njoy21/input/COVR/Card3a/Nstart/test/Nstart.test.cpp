#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nstart output values",
  "[COVR], [Card3a], [Nstart]"){
  GIVEN( "valid inputs for nstart" ){
    WHEN( "the nstart value is provided" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto& nstart : {0, 2, 5} ){
          iRecordStream<char> iss(
            std::istringstream( std::to_string( nstart ) ) );
          REQUIRE( nstart == argument::extract< 
            COVR::Card3a::Nstart >( iss ).value );
        }
      } // THEN
    } // WHEN

    WHEN( "no nstart value given " ){
      iRecordStream<char> iss( std::istringstream( "  /" ) );

      THEN( "default value is substituted in" ){
        REQUIRE( 1 == argument::extract< COVR::Card3a::Nstart > ( iss ).value );
      } // THEN
    } // WHEN
  
    WHEN( "nstart tapes are out of range" ){
      for( auto& nstart : {-1, -2} ){
        iRecordStream<char> iss( std::istringstream(std::to_string( nstart )) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< COVR::Card3a::Nstart>( iss ) );
        } // THEN
      }
    } // WHEN
  } // GIVEN
} // SCENARIO

