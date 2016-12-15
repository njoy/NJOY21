#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ndir output values",
         "[ACER],[Card1], [Ndir]"){

  Argument< ACER::Card1::Nendf > nendf; 
  Argument< ACER::Card1::Npend > npend; 
  Argument< ACER::Card1::Ngend > ngend; 
  Argument< ACER::Card1::Nace > nace; 
  nendf.value = 20;
  npend.value = 21;
  ngend.value = 22;
  nace.value = 23;

  GIVEN( "valid ndir input values" ){
    WHEN( "the nendf and npend values are not the same as the ndir values" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto ndir : {-24, 24, 50, 99, -99} ){
          iRecordStream<char> issNdir( 
              std::istringstream( std::to_string( ndir ) ) );
          REQUIRE( ndir == argument::extract< ACER::Card1::Ndir >(
                            issNdir, nendf, npend, ngend, nace ).value );
        }
      }
    }
    WHEN( "the npend, nendf, or ngend value and ndir values are the same" ){
      THEN( "an exception is thrown" ){
        int ndir = 24;
        nace.value = ndir;
        iRecordStream<char> issNdir( 
            std::istringstream( std::to_string( ndir ) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card1::Ndir >(
                          issNdir, nendf, npend, ngend, nace ) );

        nace.value = 23;
        nendf.value = ndir;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Ndir >(
                          issNdir, nendf, npend, ngend, nace ) );

        nendf.value = 20;
        npend.value = ndir;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Ndir >(
                          issNdir, nendf, npend, ngend, nace ) );

        npend.value = 22;
        ngend.value = ndir;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Ndir >(
                          issNdir, nendf, npend, ngend, nace ) );
      }
    }
  } // GIVEN

  GIVEN( "invalid ndir tape values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    for( auto npend : invalidValues ){
      iRecordStream<char> issNpend(
          std::istringstream( std::to_string(npend) ) );
      REQUIRE_THROWS(argument::extract<ACER::Card1::Npend>(
              issNpend, nendf));
    }
  } // GIVEN
}
