#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Yh output values", "[PLOTR],[Card6], [Yh]"){

  GIVEN( "valid entries" ){
    WHEN( "valid Yh parameters" ){
      Argument< PLOTR::Card6::Yl > yl;
      yl.value = 0.0;
  
      std::vector<double> validValues{0.01,0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto yh : validValues ){
          iRecordStream<char> issYh( 
              std::istringstream( std::to_string( yh ) ) );
  
          REQUIRE( yh == *( argument::extract< PLOTR::Card6::Yh >( 
                            issYh, yl.value ).value ) );
        }
      }
    }
  
    WHEN( "default value" ){
      Argument< PLOTR::Card6::Yl > yl;
      iRecordStream<char> issYh( std::istringstream( " /" ) );
      
      THEN( "default value is returned" ){
        REQUIRE( std::nullopt == argument::extract< PLOTR::Card6::Yh >(
                            issYh, yl.value ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid entries" ){
    WHEN( "Yh is less than Yl" ){
      Argument< PLOTR::Card6::Yl > yl; yl.value = 20.0;
      iRecordStream<char> issYh( std::istringstream( " 10.0 / " ) );
  
      REQUIRE_THROWS( argument::extract< PLOTR::Card6::Yh >( issYh, yl.value ) );
    }
  
    WHEN( "Yh uses the default but Yl didn't" ){
      Argument< PLOTR::Card6::Yl > yl; yl.value = 10.0;
      iRecordStream<char> issYh( std::istringstream( " / " ) );
  
      REQUIRE_THROWS( argument::extract< PLOTR::Card6::Yh >( issYh, yl.value ) );
    }
  } // GIVEN
} // SCENARIO
