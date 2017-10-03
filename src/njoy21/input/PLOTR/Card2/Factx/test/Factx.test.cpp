#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Factx output values", "[PLOTR],[Card2], [Factx]"){

  GIVEN( "valid Factx parameters" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto factx : validValues ){
        iRecordStream<char> issFactx( 
            std::istringstream( std::to_string( factx ) ) );

        REQUIRE( factx == argument::extract< PLOTR::Card2::Factx >( 
                          issFactx ).value );
      }
    }
  } // GIVEN

  GIVEN( "no Factx parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issFactx( std::istringstream( " /" ) );
      REQUIRE( 1.0f == argument::extract< PLOTR::Card2::Factx >( 
                         issFactx ).value );
    }
  } //GIVEN

  GIVEN( "invalid Factx parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    THEN( "the class throws an exception" ){
      for( auto factx : invalidValues ){
        iRecordStream<char> issFactx( 
            std::istringstream( std::to_string( factx ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card2::Factx >( issFactx ) );
      }
    }
  } // GIVEN
} // SCENARIO
