#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nace output values",
         "[ACER],[Card1], [Nace]"){

  Argument< ACER::Card1::Nendf > nendf; 
  Argument< ACER::Card1::Npend > npend; 
  Argument< ACER::Card1::Ngend > ngend; 
  nendf.value = 23;
  npend.value = 21;
  ngend.value = 22;

  GIVEN( "valid nace input values" ){
    WHEN( "the nendf and npend values are not the same as the nace values" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto nace : {-20, 20, 50, 99, -99} ){
          iRecordStream<char> issNace( 
              std::istringstream(std::to_string( nace ) ) );
          REQUIRE( nace == argument::extract< ACER::Card1::Nace >(
                            issNace, nendf, npend, ngend ).value );
        }
      }
    }
    WHEN( "the npend, nendf, or ngend value and nace values are the same" ){
      THEN( "an exception is thrown" ){
        int nace = 23;
        ngend.value = nace;
        iRecordStream<char> issNace( 
            std::istringstream(std::to_string( nace ) ) );
        REQUIRE_THROWS( argument::extract< ACER::Card1::Nace >(
                          issNace, nendf, npend, ngend ) );

        ngend.value = 22;
        nendf.value = nace;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Nace >(
                          issNace, nendf, npend, ngend ) );

        nendf.value = 20;
        npend.value = nace;
        REQUIRE_THROWS( argument::extract< ACER::Card1::Nace >(
                          issNace, nendf, npend, ngend ) );

      }
    }
  } // GIVEN

  GIVEN( "invalid nace tape values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    for( auto npend : invalidValues ){
      iRecordStream<char> issNpend(
          std::istringstream(std::to_string(npend)) );
      REQUIRE_THROWS(argument::extract<ACER::Card1::Npend>(
              issNpend, nendf));
    }
  } // GIVEN
}
