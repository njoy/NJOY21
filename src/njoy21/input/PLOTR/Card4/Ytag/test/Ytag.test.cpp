#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ytag output values", "[PLOTR],[Card4], [Ytag]"){

  GIVEN( "valid Ytag parameters" ){
    std::vector<float> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto ytag : validValues ){
        iRecordStream<char> issYtag( 
            std::istringstream( std::to_string( ytag ) ) );

        REQUIRE( ytag == argument::extract< PLOTR::Card4::Ytag >( 
                          issYtag ).value );
      }
    }
  } // GIVEN

  GIVEN( "no Ytag parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issYtag( std::istringstream( " /" ) );
      REQUIRE( true == argument::extract< PLOTR::Card4::Ytag >( 
                         issYtag ).value );
    }
  } //GIVEN

  GIVEN( "invalid Ytag parameters" ){
    std::vector<float> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto ytag : invalidValues ){
        iRecordStream<char> issYtag( 
            std::istringstream( std::to_string( ytag ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card4::Ytag >( issYtag ) );
      }
    }
  } // GIVEN
} // SCENARIO
