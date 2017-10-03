#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ww output values", "[PLOTR],[Card2], [Ww]"){

  GIVEN( "valid Ww parameters" ){
    WHEN( "the available size is 7.5 inches" ){
      const int lori = 1;
      std::vector<double> validValues{0.5, 1.0, 4.8, 8.0, 10.0, 11.0};

      THEN( "the returned class has the correct value" ){
        for( auto ww : validValues ){
          iRecordStream<char> issWw( 
              std::istringstream( std::to_string( ww ) ) );

          REQUIRE( ww == argument::extract< PLOTR::Card2::Ww >( 
                            issWw, lori ).value );
        }
      }
    }
    WHEN( "the available size is 10.0 inches" ){
      const int lori = 0;
      std::vector<double> validValues{0.5, 1.0, 4.8, 10.5, 11.0};

      THEN( "the returned class has the correct value" ){
        for( auto ww : validValues ){
          iRecordStream<char> issWw( 
              std::istringstream( std::to_string( ww ) ) );

          REQUIRE( ww == argument::extract< PLOTR::Card2::Ww >( 
                            issWw, lori ).value );
        }
      }
    }
  } // GIVEN

  GIVEN( "no Ww parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issWw( std::istringstream( " /" ) );
      REQUIRE( APPROX( 10.0 ) == argument::extract< PLOTR::Card2::Ww >( 
                         issWw, 1 ).value );
    }
    THEN( "the default value is returned" ){
      iRecordStream<char> issWw( std::istringstream( " /" ) );
      REQUIRE( APPROX( 7.5 ) == argument::extract< PLOTR::Card2::Ww >( 
                         issWw, 0 ).value );
    }
  } //GIVEN

  GIVEN( "invalid Ww parameters" ){
    WHEN( "the available size is 7.5 inches" ){
      std::vector<double> invalidValues{ -2.0, -1.0, -0.5, 11.1 };

      THEN( "the returned class has the correct value" ){
        for( auto ww : invalidValues ){
          iRecordStream<char> issWw( 
              std::istringstream( std::to_string( ww ) ) );

          REQUIRE_THROWS( argument::extract< PLOTR::Card2::Ww >( issWw, 0 ) );
        }
      }
    }
    WHEN( "the available size is 10.0 inches" ){
      std::vector<double> invalidValues{ -2.0, -1.1, -0.51, 11.1 };

      THEN( "the returned class has the correct value" ){
        for( auto ww : invalidValues ){
          iRecordStream<char> issWw( 
              std::istringstream( std::to_string( ww ) ) );

          REQUIRE_THROWS( argument::extract< PLOTR::Card2::Ww >( issWw, 1 ));
        }
      }
    }
  } // GIVEN
} // SCENARIO
