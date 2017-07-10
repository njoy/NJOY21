#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Thin2  output values",
         "[ACER],[Card7], [thin2]"){
  Argument< ACER::Card7::Thin1 > thin1;
  thin1.value = 3.0;
  GIVEN( "valid thin2 values" ){
    std::vector<double> validValues{0.0, 0.001, 1E4, 1.0, 2};

    THEN( "the returned class has the correct value" ){
      for( auto& thin2 : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(thin2) ) );
        njoy::Log::info("Valid value {}", thin2);

        REQUIRE( thin2*dimwits::electronVolt == 
                 argument::extract< ACER::Card7::Thin2 >( iss, thin1 ).value );
      }
    }
  }
  GIVEN( "no thin2 value" ){
    thin1.value = 0.0;
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0.0*dimwits::electronVolt == 
               argument::extract< ACER::Card7::Thin2 >( iss, thin1 ).value );
    }
  }
  GIVEN( "invalid thin2 values" ){
    WHEN( "thin2 is negative" ){
      thin1.value = 3.0;
      iRecordStream<char> iss( std::istringstream( " -1.0 /") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ACER::Card7::Thin2 >( iss, thin1 ) );
      }
    }
    WHEN( "thin2 is greater than thin1" ){
      thin1.value = -4.0;
      iRecordStream<char> iss( std::istringstream( " 3.0 /") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ACER::Card7::Thin2 >( iss, thin1 ) );
      }
    }
  }
}
