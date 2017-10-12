#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Yerr1 output values", "[PLOTR],[Card13], [Yerr1]"){

  GIVEN( "valid Yerr1 parameters" ){
    std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto yerr1 : validValues ){
        iRecordStream<char> issYerr1( 
            std::istringstream( std::to_string( yerr1 ) ) );

        REQUIRE( yerr1 == argument::extract< PLOTR::Card13::Yerr1 >( 
                          issYerr1 ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid Yerr1 parameters" ){
    std::vector<double> invalidValues{-2.0, -1.0};

    THEN( "the returned class has the correct value" ){
      for( auto yerr1 : invalidValues ){
        iRecordStream<char> issYerr1( 
            std::istringstream( std::to_string( yerr1 ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card13::Yerr1 >( 
                          issYerr1 ).value );
      }
    }
  } // GIVEN

} // SCENARIO
