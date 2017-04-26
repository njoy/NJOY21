#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ninwt output values", "[GROUPR],[Card8a], [Ninwt]"){

  GIVEN( "valid Ninwt parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto ninwt : {0, -22, 22, 50, 99, -99} ){
        iRecordStream<char> issNinwt( 
            std::istringstream( std::to_string( ninwt ) ) );

        REQUIRE( ninwt == argument::extract< GROUPR::Card8a::Ninwt >( 
                          issNinwt ).value );
      }
    }
  } // GIVEN
  GIVEN( "no ninwt value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( GROUPR::Card8a::Ninwt::defaultValue() == 
                argument::extract< GROUPR::Card8a::Ninwt >( iss ).value );
    }
  }
  GIVEN( "invalid Ninwt parameters" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};

    THEN( "the returned class has the correct value" ){
      for( auto ninwt : invalidValues ){
        njoy::Log::debug("ninwt: {}", ninwt);
        iRecordStream<char> issNinwt( 
            std::istringstream( std::to_string( ninwt ) ) );

        REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Ninwt >( issNinwt ) );
      }
    }
  } // GIVEN
} // SCENARIO
