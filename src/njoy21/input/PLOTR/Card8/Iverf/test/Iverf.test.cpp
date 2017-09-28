#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Iverf output values", "[PLOTR],[Card8], [Iverf]"){

  GIVEN( "valid Iverf parameters" ){
    std::vector<int> validValues{0,1,2,3,4,5,6,7,8};

    THEN( "the returned class has the correct value" ){
      for( auto iverf : validValues ){
        iRecordStream<char> issIverf( 
            std::istringstream( std::to_string( iverf ) ) );

        REQUIRE( iverf == argument::extract< PLOTR::Card8::Iverf >( 
                          issIverf ).value );
      }
    }
  } // GIVEN
  GIVEN( "no Iverf parameter" ){
    THEN( "the default is returned" ){
      iRecordStream<char> issIverf(std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< PLOTR::Card8::Iverf >( issIverf ).value );
    }
  }//GIVEN
  GIVEN( "invalid Iverf parameters" ){
    std::vector<int> invalidValues{ -1,9 };

    THEN( "the returned class has the correct value" ){
      for( auto iverf : invalidValues ){
        iRecordStream<char> issIverf( 
            std::istringstream( std::to_string( iverf ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card8::Iverf >( issIverf ) );
      }
    }
  } // GIVEN
} // SCENARIO
