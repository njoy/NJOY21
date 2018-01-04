#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ileg output values", "[PLOTR],[Card4], [Ileg]"){

  GIVEN( "valid Ileg parameters" ){
    std::vector<int> validValues{0,1,2};

    THEN( "the returned class has the correct value" ){
      for( auto ileg : validValues ){
        iRecordStream<char> issIleg( 
            std::istringstream( std::to_string( ileg ) ) );

        REQUIRE( ileg == argument::extract< PLOTR::Card4::Ileg >( 
                          issIleg ).value );
      }
    }
  } // GIVEN
  GIVEN( "no Ileg parameter" ){
    THEN( "the default is returned" ){
      iRecordStream<char> issIleg(std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< PLOTR::Card4::Ileg >( issIleg ).value );
    }
  }//GIVEN
  GIVEN( "invalid Ileg parameters" ){
    std::vector<int> invalidValues{ -1,3 };

    THEN( "the returned class has the correct value" ){
      for( auto ileg : invalidValues ){
        iRecordStream<char> issIleg( 
            std::istringstream( std::to_string( ileg ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card4::Ileg >( issIleg ) );
      }
    }
  } // GIVEN
} // SCENARIO
