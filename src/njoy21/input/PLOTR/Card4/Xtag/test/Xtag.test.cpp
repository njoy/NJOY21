#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Xtag output values", "[PLOTR],[Card4], [Xtag]"){

  GIVEN( "valid Xtag parameters" ){
    std::vector<float> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto& xtag : validValues ){
        iRecordStream<char> issXtag( 
            std::istringstream( std::to_string( 0.0 ) ) );

        REQUIRE( xtag == *( argument::extract< PLOTR::Card4::Xtag >( 
                          issXtag ).value ) );
      }
    }
  } // GIVEN

  GIVEN( "no Xtag parameter provided" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> issXtag( std::istringstream( " /" ) );
      REQUIRE( not argument::extract< PLOTR::Card4::Xtag >( issXtag ).value );
    }
  } //GIVEN

  GIVEN( "invalid Xtag parameters" ){
    std::vector<float> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto& xtag : invalidValues ){
        iRecordStream<char> issXtag( 
            std::istringstream( std::to_string( xtag ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card4::Xtag >( issXtag ) );
      }
    }
  } // GIVEN
} // SCENARIO
