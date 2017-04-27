#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ec output values", "[GROUPR],[Card8c], [Ec]"){

  GIVEN( "valid Ec parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto ec : { 1.0, 1E-3, 10.0} ){
        iRecordStream<char> issEc( 
            std::istringstream( std::to_string( ec ) ) );

        REQUIRE( ec*dimwits::electronVolt == 
                argument::extract< GROUPR::Card8c::Ec >( issEc ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Ec parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto ec : {-1.0, 0.0}){
        iRecordStream<char> issEc( 
            std::istringstream( std::to_string( ec ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8c::Ec >( issEc ) );
      }
    }
  } // GIVEN
} // SCENARIO
