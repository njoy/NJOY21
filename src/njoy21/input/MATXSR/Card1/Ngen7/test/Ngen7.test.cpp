#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card1 Ngen7 values",
          "[MATXSR],[Card1],[Ngen7]" ){

  const int ngen1 = 24;
  const int ngen2 = 25;
  const int nmatx = 26;
  const int ngen3 = 27;
  const int ngen4 = 28;
  const int ngen5 = 29;
  const int ngen6 = 30;

  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {-99,-40,-20,20,97,99} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< MATXSR::Card1::Ngen7 >(
                 iss, ngen6, ngen5, ngen4, ngen3, nmatx, ngen2, ngen1 ).value );
        }
      }
    }

    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value is returned" ){
        REQUIRE( 0 == argument::extract< MATXSR::Card1::Ngen7 >(
                 iss, ngen6, ngen5, ngen4, ngen3, nmatx, ngen2, ngen1 ).value );
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( auto i :
         {-100,-30,-29,-28,-27,-26,-25,-24,-19,0,19,24,25,26,27,28,29,30,100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< MATXSR::Card1::Ngen7 >(
                       iss, ngen6, ngen5, ngen4, ngen3, nmatx, ngen2, ngen1 ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
