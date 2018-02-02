#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Matd  output values", "[PLOTR],[Card8], [Matd]"){
  int iverf = 2;
  GIVEN( "valid matd values" ){
    std::vector<int> validValues{ 1, 1001, 9238, 9999 };

    THEN( "the returned class has the correct value" ){
      for( auto matd : validValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string( matd ) ) );

        REQUIRE( 
          matd == argument::extract< PLOTR::Card8::Matd >( iss, iverf ).value );
      }
    }
  }//GIVEN
  GIVEN( "invalid matd values" ){
    std::vector<int> invalidValues{-1, -2, 10000};

    THEN( "an exception is thrown" ){
      for( auto matd : invalidValues ){
        iRecordStream<char> iss(
            std::istringstream( std::to_string(matd) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card8::Matd >( iss, iverf ) );
      }
    }
  }//GIVEN
  GIVEN( "Iverf == 0" ){
    iverf = 0;
    std::vector<int> meaninglessMatd{ -2, -1, 0, 1, 10001, 92238, 9999, 10000 };
    THEN( "the values don't matter" ){
      for( auto matd : meaninglessMatd ){
        iRecordStream<char> iss( std::istringstream( std::to_string( matd ) ) );
        REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Matd >(
                                            iss, iverf ) );
      }
    }
  }//GIVEN
}
