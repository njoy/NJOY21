#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tempd input values", "[ACER], [Card4], [Tempd]" ){
  GIVEN( "valid tempd values" ){
    std::vector<double> validTempd{ 0.0, 293.6 };

    THEN( "the returned class has the correct value" ){
      for( auto tempd : validTempd ){
	iRecordStream<char> issTempd( std::istringstream( std::to_string(tempd) ) );
        auto tempdArg = argument::extract< RECONR::Card4::Tempd >(issTempd );
        REQUIRE( tempd * dimwits::kelvin == tempdArg.value );
      }
    }
  }
  GIVEN( "invalid tempd values" ){
    double tempd(-0.01);
    THEN( "an exception is thrown" ){
      iRecordStream<char> issTempd( std::istringstream( std::to_string(tempd) ) );
      REQUIRE_THROWS( argument::extract< RECONR::Card4::Tempd >(issTempd) );
    }
  }
}

