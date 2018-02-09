#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Itype output values", "[PLOTR],[Card4], [Itype]"){

  GIVEN( "valid Itype parameters" ){
    std::vector<int> validValues{-4,-3,-2,-1,1,2,3,4};

    THEN( "the returned class has the correct value" ){
      for( auto itype : validValues ){
        iRecordStream<char> issItype( 
            std::istringstream( std::to_string( itype ) ) );

        REQUIRE( itype == argument::extract< PLOTR::Card4::Itype >( 
                          issItype ).value );
      }
    }
  } // GIVEN
  GIVEN( "no Itype parameter" ){
    THEN( "the default is returned" ){
      iRecordStream<char> issItype(std::istringstream( " /" ) );
      REQUIRE( 4 == argument::extract< PLOTR::Card4::Itype >( issItype ).value );
    }
  }//GIVEN
  GIVEN( "invalid Itype parameters" ){
    std::vector<int> invalidValues{ -5,0,5 };

    THEN( "the returned class has the correct value" ){
      for( auto itype : invalidValues ){
        iRecordStream<char> issItype( 
            std::istringstream( std::to_string( itype ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card4::Itype >( issItype ) );
      }
    }
  } // GIVEN
} // SCENARIO
