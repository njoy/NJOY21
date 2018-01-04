#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ll output values", "[PLOTR],[Card2], [Ll]"){

  GIVEN( "valid Ll parameters" ){
    WHEN( "the available size is 7.5 inches" ){
      const double size = 7.5;
      std::vector<double> validValues{-0.5, -0.1, 0.0, 0.5, 1.0, 4.8, 8.0};

      THEN( "the returned class has the correct value" ){
        for( auto ll : validValues ){
          iRecordStream<char> issLl( 
              std::istringstream( std::to_string( ll ) ) );

          REQUIRE( ll == argument::extract< PLOTR::Card2::Ll >( 
                            issLl, size ).value );
        }
      }
    }
    WHEN( "the available size is 10.0 inches" ){
      const double size = 10.0;
      std::vector<double> validValues{-0.5, -0.1, 0.0, 0.5, 1.0, 4.8, 10.5};

      THEN( "the returned class has the correct value" ){
        for( auto ll : validValues ){
          iRecordStream<char> issLl( 
              std::istringstream( std::to_string( ll ) ) );

          REQUIRE( ll == argument::extract< PLOTR::Card2::Ll >( 
                            issLl, size ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "no Ll parameter provided" ){
    THEN( "the default value is returned with 7.5 added" ){
      iRecordStream<char> issLl( std::istringstream( " /" ) );
      REQUIRE( Approx( 0.0 ) == argument::extract< PLOTR::Card2::Ll >( 
                         issLl, 7.5 ).value );
    }
    THEN( "the default value is returned with 10.0 added" ){
      iRecordStream<char> issLl( std::istringstream( " /" ) );
      REQUIRE( Approx( 0.0 ) == argument::extract< PLOTR::Card2::Ll >( 
                         issLl, 10.0 ).value );
    }
  } //GIVEN

  GIVEN( "invalid Ll parameters" ){
    WHEN( "the available size is 7.5 inches" ){
      std::vector<double> invalidValues{ -2.0, -1.1, -0.51, 8.01 };

      THEN( "the returned class has the correct value" ){
        for( auto ll : invalidValues ){
          iRecordStream<char> issLl( 
              std::istringstream( std::to_string( ll ) ) );

          REQUIRE_THROWS( argument::extract< PLOTR::Card2::Ll >( issLl, 7.5 ) );
        }
      }
    }
    WHEN( "the available size is 10.0 inches" ){
      std::vector<double> invalidValues{ -2.0, -1.1, -0.51, 10.51 };

      THEN( "the returned class has the correct value" ){
        for( auto ll : invalidValues ){
          iRecordStream<char> issLl( 
              std::istringstream( std::to_string( ll ) ) );

          REQUIRE_THROWS( argument::extract< PLOTR::Card2::Ll >( issLl, 10.0 ));
        }
      }
    }
  } // GIVEN
} // SCENARIO
