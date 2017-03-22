#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tempd input values", "[ACER], [Card8], [Tempd]" ){
  GIVEN( "valid tempd values" ){
    std::vector<double> validTempd{ 0.0, 293.6 };

    THEN( "the returned class has the correct value" ){
      for( auto tempd : validTempd ){
        iRecordStream<char> issTempd( 
            std::istringstream( std::to_string(tempd) ) );
        auto tempdArg = argument::extract< ACER::Card8::Tempd >(issTempd );
        REQUIRE( tempd * dimwits::kelvin == tempdArg.value );
      }
    }
  }
  GIVEN( "no tempd value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( ACER::Card5::Tempd::defaultValue() == 
                argument::extract< ACER::Card5::Tempd >( iss ).value );
    }
  }
  GIVEN( "invalid tempd values" ){
    double tempd(-0.01);
    THEN( "an exception is thrown" ){
      iRecordStream<char> issTempd( std::istringstream( std::to_string(tempd) ) );
      REQUIRE_THROWS( argument::extract< ACER::Card8::Tempd >(issTempd) );
    }
  }
}

