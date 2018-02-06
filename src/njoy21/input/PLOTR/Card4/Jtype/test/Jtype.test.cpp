#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Jtype output values", "[PLOTR],[Card4], [Jtype]"){

  GIVEN( "valid Jtype parameters" ){
    std::vector<int> validValues{0,1,2};

    THEN( "the returned class has the correct value" ){
      for( auto jtype : validValues ){
        iRecordStream<char> issJtype( 
            std::istringstream( std::to_string( jtype ) ) );

        REQUIRE( jtype == argument::extract< PLOTR::Card4::Jtype >( 
                          issJtype ).value );
      }
    }
  } // GIVEN
  GIVEN( "no Jtype parameter" ){
    THEN( "the default is returned" ){
      iRecordStream<char> issJtype(std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract< PLOTR::Card4::Jtype >( issJtype ).value );
    }
  }//GIVEN
  GIVEN( "invalid Jtype parameters" ){
    std::vector<int> invalidValues{ -1,3 };

    THEN( "the returned class has the correct value" ){
      for( auto jtype : invalidValues ){
        iRecordStream<char> issJtype( 
            std::istringstream( std::to_string( jtype ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card4::Jtype >( issJtype ) );
      }
    }
  } // GIVEN
} // SCENARIO
