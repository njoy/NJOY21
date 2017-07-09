#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tc output values", "[GROUPR],[Card8c], [Tc]"){

  GIVEN( "valid Tc parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto tc : { 1.0, 1E-3, 10.0} ){
        iRecordStream<char> issTc( 
            std::istringstream( std::to_string( tc ) ) );

        REQUIRE( tc*dimwits::electronVolt == 
                argument::extract< GROUPR::Card8c::Tc >( issTc ).value );
      }
    }
  } // GIVEN
  GIVEN( "invalid Tc parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto tc : {-1.0, 0.0}){
        iRecordStream<char> issTc( 
            std::istringstream( std::to_string( tc ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8c::Tc >( issTc ) );
      }
    }
  } // GIVEN
} // SCENARIO
