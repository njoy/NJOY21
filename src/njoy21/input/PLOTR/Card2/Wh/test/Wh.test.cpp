#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Wh output values", "[PLOTR],[Card2], [Wh]"){

  GIVEN( "valid Wh parameters" ){
    WHEN( "the available size is 7.5 inches" ){
      const int lori = 1;
      std::vector<float> validValues{0.5, 1.0, 4.8, 8.0, 11.0};

      THEN( "the returned class has the correct value" ){
        for( auto wh : validValues ){
          iRecordStream<char> issWh( 
              std::istringstream( std::to_string( wh ) ) );

          REQUIRE( wh == argument::extract< PLOTR::Card2::Wh >( 
                            issWh, lori ).value );
        }
      }
    }
    WHEN( "the available size is 10.0 inches" ){
      const int lori = 0;
      std::vector<float> validValues{0.5, 1.0, 4.8, 10.5, 11.0};

      THEN( "the returned class has the correct value" ){
        for( auto wh : validValues ){
          iRecordStream<char> issWh( 
              std::istringstream( std::to_string( wh ) ) );

          REQUIRE( wh == argument::extract< PLOTR::Card2::Wh >( 
                            issWh, lori ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "no Wh parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issWh( std::istringstream( " /" ) );
      REQUIRE( APPROX( 7.5 ) == argument::extract< PLOTR::Card2::Wh >( 
                         issWh, 1 ).value );
    }
    THEN( "the default value is returned" ){
      iRecordStream<char> issWh( std::istringstream( " /" ) );
      REQUIRE( APPROX( 10.0 ) == argument::extract< PLOTR::Card2::Wh >( 
                         issWh, 0 ).value );
    }
  } //GIVEN

  GIVEN( "invalid Wh parameters" ){
    WHEN( "the available size is 7.5 inches" ){
      std::vector<float> invalidValues{ -2.0, -1.0, -0.5, 11.1 };

      THEN( "the returned class has the correct value" ){
        for( auto wh : invalidValues ){
          iRecordStream<char> issWh( 
              std::istringstream( std::to_string( wh ) ) );

          REQUIRE_THROWS( argument::extract< PLOTR::Card2::Wh >( issWh, 0 ) );
        }
      }
    }
    WHEN( "the available size is 10.0 inches" ){
      std::vector<float> invalidValues{ -2.0, -1.1, -0.51, 11.1 };

      THEN( "the returned class has the correct value" ){
        for( auto wh : invalidValues ){
          iRecordStream<char> issWh( 
              std::istringstream( std::to_string( wh ) ) );

          REQUIRE_THROWS( argument::extract< PLOTR::Card2::Wh >( issWh, 1 ));
        }
      }
    }
  } // GIVEN
} // SCENARIO
