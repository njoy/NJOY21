#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Thin1  output values",
         "[ACER],[Card7], [Thin1]"){
  GIVEN( "valid thin1 values" ){
    std::vector<double> validValues{0.001, 1E4, 1.0, 2, -1.0, -1E-6};

    THEN( "the returned class has the correct value" ){
      for( auto& thin1 : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin1) ) );

        REQUIRE( 
          thin1 == argument::extract< ACER::Card7::Thin1 >( iss ).value );
      }
    }
  }
  GIVEN( "no thin1 value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( ACER::Card7::Thin1::defaultValue() == 
                argument::extract< ACER::Card7::Thin1 >( iss ).value );
    }
  }
  GIVEN( "invalid thin1 values" ){
    std::vector<double> invalidValues{};

    THEN( "an exception is thrown" ){
      for( auto& thin1 : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin1) ) );

        REQUIRE_THROWS( argument::extract< ACER::Card7::Thin1 >( iss ) );
      }
    }
  }
}
