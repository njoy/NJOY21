#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tempr input values", "[Card4], [Tempr]" ){
  GIVEN( "valid tempr values" ){
    std::vector<double> validTempr{ 0.0, 293.6 };

    THEN( "the returned class has the correct value" ){
      for( auto tempr : validTempr ){
	iRecordStream<char> issTempr( std::istringstream( std::to_string(tempr) ) );
        auto temprArg = argument::extract< RECONR::Card4::Tempr >(issTempr );
        REQUIRE( tempr * dimwits::kelvin == temprArg.value );
      }
    }
  }
  GIVEN( "invalid tempr values" ){
    double tempr(-0.01);
    THEN( "an exception is thrown" ){
      iRecordStream<char> issTempr( std::istringstream( std::to_string(tempr) ) );
      REQUIRE_THROWS( argument::extract< RECONR::Card4::Tempr >(issTempr) );
    }
  }
}

