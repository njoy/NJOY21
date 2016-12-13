#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ngend output values",
         "[ACER],[Card1], [Ngend]"){

  long ln{0};
  Argument< ACER::Card1::Nendf > nendf; 
  Argument< ACER::Card1::Npend > npend; 
  nendf.value = 20;

  GIVEN( "valid ngend input values" ){
    WHEN( "the nendf and npend values are not the same as the ngend values" ){
      npend.value = 21;

      THEN( "the returned class has the correct tape value" ){
        for( auto ngend : {0, -22, 22, 50, 99, -99} ){
          std::istringstream issNgend( std::to_string( ngend ) );
          REQUIRE( ngend == argument::extract< ACER::Card1::Ngend >(
                            issNgend, ln, nendf, npend ).value );
        }
      }
    }
    WHEN( "the npend or nendf value and ngend values are the same" ){
      THEN( "an exception is thrown" ){
        int ngend = 22;
        npend.value = ngend;
        std::istringstream issNgend( std::to_string( ngend ) );
        REQUIRE_THROWS( argument::extract< ACER::Card1::Ngend >(
                          issNgend, ln, nendf, npend ) );

        nendf.value = 22;
        npend.value = 21;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Ngend >(
                          issNgend, ln, nendf, npend ) );

      }
    }
  } // GIVEN

  GIVEN( "invalid ngend tape values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    for( auto npend : invalidValues ){
      std::istringstream issNpend(std::to_string(npend));
      REQUIRE_THROWS(argument::extract<ACER::Card1::Npend>(
              issNpend, ln, nendf));
    }
  } // GIVEN
}
