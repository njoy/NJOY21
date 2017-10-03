#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Facty output values", "[PLOTR],[Card2], [Facty]"){

  GIVEN( "valid Facty parameters" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto facty : validValues ){
        iRecordStream<char> issFacty( 
            std::istringstream( std::to_string( facty ) ) );

        REQUIRE( facty == argument::extract< PLOTR::Card2::Facty >( 
                          issFacty ).value );
      }
    }
  } // GIVEN

  GIVEN( "no Facty parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issFacty( std::istringstream( " /" ) );
      REQUIRE( 1.0f == argument::extract< PLOTR::Card2::Facty >( 
                         issFacty ).value );
    }
  } //GIVEN

  GIVEN( "invalid Facty parameters" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    THEN( "the returned class has the correct value" ){
      for( auto facty : invalidValues ){
        iRecordStream<char> issFacty( 
            std::istringstream( std::to_string( facty ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card2::Facty >( issFacty ) );
      }
    }
  } // GIVEN
} // SCENARIO
