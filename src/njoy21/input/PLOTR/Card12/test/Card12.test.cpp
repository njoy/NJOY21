#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card12 inputs",
          "[PLOTR], [Card12]" ){

  GIVEN( "valid PLOTR Card12 inputs" ){
    std::vector<int> validNform{0,1,2,3,4};
    WHEN( "All values are given" ){
      for( auto nform : validNform ){
        iRecordStream<char> issCard12( std::istringstream(
                              std::to_string( nform ) ) );

        PLOTR::Card12 card12(issCard12);

        THEN( "the members can be tested" ){
          REQUIRE( nform == card12.nform.value );
        }//THEN
      }
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "The value is wrong" ){
      iRecordStream<char> issCard12( std::istringstream(
             "-1 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card12(issCard12) );
      }
    }//WHEN
    WHEN( "No value is given" ){
      iRecordStream<char> issCard12( std::istringstream(
            " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card12(issCard12) );
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard12( std::istringstream(
            "10 18 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card12(issCard12) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
