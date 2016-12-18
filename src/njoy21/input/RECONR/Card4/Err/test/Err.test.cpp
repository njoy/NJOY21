#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "err input values", "[Card4], [Err]"){
  GIVEN( "valid err values" ){
    std::vector<double> validErr{ 0.1, 1.0, 1E6 };

    THEN( "the returned class has the correct value" ){
      for( auto err : validErr ){
	iRecordStream<char> issErr( std::istringstream( std::to_string(err) ) );
        REQUIRE( err == argument::extract< RECONR::Card4::Err >(issErr).value );
      }
    }
  }
} 
