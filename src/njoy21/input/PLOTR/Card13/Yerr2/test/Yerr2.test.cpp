#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Yerr2 output values", "[PLOTR],[Card13], [Yerr2]"){

  const double yerr1 = 3.0;

  GIVEN( "valid Yerr2 parameters" ){
    std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto yerr2 : validValues ){
        iRecordStream<char> issYerr2( 
            std::istringstream( std::to_string( yerr2 ) ) );

        REQUIRE( yerr2 == argument::extract< PLOTR::Card13::Yerr2 >( 
                          issYerr2, yerr1 ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid Yerr2 parameters" ){
    std::vector<double> invalidValues{-2.0, -1.0};

    THEN( "the returned class has the correct value" ){
      for( auto yerr2 : invalidValues ){
        iRecordStream<char> issYerr2( 
            std::istringstream( std::to_string( yerr2 ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card13::Yerr2 >( 
                          issYerr2, yerr1 ) );
      }
    }
  } // GIVEN

} // SCENARIO
