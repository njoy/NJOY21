#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Temp input values" ){
  GIVEN( "valid temp values" ){
    std::vector<double> validTemp{ 0.0, 293.6, 500.0 };
    THEN( "the returned class has the correct value" ){
      for( auto temp : validTemp ){
        iRecordStream<char> issTemp( std::istringstream(
	  std::to_string(temp) ) );
	auto tempArg = argument::extract< MIXR::Card4::Temp >(issTemp);
	REQUIRE( temp * dimwits::kelvin == tempArg.value );
      }
    }
  }

  GIVEN( "invalid temp values" ){
    std::vector<double> invalidTemp{ -0.1, -293.6, -500.0 };
    THEN( "an exception is thrown" ){
      for( auto temp : invalidTemp ){
        iRecordStream<char> issTemp( std::istringstream(
	  std::to_string(temp) ) );
	REQUIRE_THROWS( argument::extract< MIXR::Card4::Temp >(issTemp) );
      }
    }
  }
}
