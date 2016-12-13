#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nace output values",
         "[ACER],[Card1], [Nace]"){

  long ln{0};
  Argument< ACER::Card1::Nendf > nendf; 
  Argument< ACER::Card1::Npend > npend; 
  Argument< ACER::Card1::Ngend > ngend; 
  nendf.value = 20;
  npend.value = 21;
  ngend.value = 22;

  GIVEN( "valid nace input values" ){
    WHEN( "the nendf and npend values are not the same as the nace values" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto nace : {-23, 23, 50, 99, -99} ){
          std::istringstream issNace( std::to_string( nace ) );
          REQUIRE( nace == argument::extract< ACER::Card1::Nace >(
                            issNace, ln, nendf, npend, ngend ).value );
        }
      }
    }
    WHEN( "the npend, nendf, or ngend value and nace values are the same" ){
      THEN( "an exception is thrown" ){
        int nace = 23;
        ngend.value = nace;
        std::istringstream issNace( std::to_string( nace ) );
        REQUIRE_THROWS( argument::extract< ACER::Card1::Nace >(
                          issNace, ln, nendf, npend, ngend ) );

        ngend.value = 22;
        nendf.value = nace;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Nace >(
                          issNace, ln, nendf, npend, ngend ) );

        nendf.value = 20;
        npend.value = nace;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Nace >(
                          issNace, ln, nendf, npend, ngend ) );

      }
    }
  } // GIVEN

  GIVEN( "invalid nace tape values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    for( auto npend : invalidValues ){
      std::istringstream issNpend(std::to_string(npend));
      REQUIRE_THROWS(argument::extract<ACER::Card1::Npend>(
              issNpend, ln, nendf));
    }
  } // GIVEN
}
