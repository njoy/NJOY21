#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Yh output values", "[PLOTR],[Card6], [Yh]"){

  Argument< PLOTR::Card6::Yl > yl;
  yl.value = 0.0;

  GIVEN( "valid Yh parameters" ){
    std::vector<double> validValues{0.01,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto yh : validValues ){
        iRecordStream<char> issYh( 
            std::istringstream( std::to_string( yh ) ) );

        REQUIRE( yh == argument::extract< PLOTR::Card6::Yh >( 
                          issYh, yl ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issYh( std::istringstream( " /" ) );
    
    THEN( "default value is returned" ){
      REQUIRE( 1.0f == argument::extract< PLOTR::Card6::Yh >(
                          issYh, yl ).value );
    }
  }//GIVEN

  GIVEN( "invalid Yh parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto yh : invalidValues ){
        iRecordStream<char> issYh( 
            std::istringstream( std::to_string( yh ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card6::Yh >( issYh, yl ) );
      }
    }
  } // GIVEN

  GIVEN( "Yh is less than Yl" ){
    iRecordStream<char> issYh( std::istringstream( " 10.0 / " ) );
    yl.value = 20.0;

    REQUIRE_THROWS( argument::extract< PLOTR::Card6::Yh >( issYh, yl ) );
  }//GIVEN
} // SCENARIO
