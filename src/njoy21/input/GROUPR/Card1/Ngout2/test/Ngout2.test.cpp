#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ngout2 output values", "[GROUPR],[Card1], [Ngout2]"){
  Argument< GROUPR::Card1::Nendf > nendf;
  Argument< GROUPR::Card1::Npend > npend;
  Argument< GROUPR::Card1::Ngout1 > ngout1;
  nendf.value = 20;
  npend.value = 21;
  ngout1.value = 22;

  GIVEN( "valid ngout2 values" ){
    WHEN( "the nendf and npend values are not the same as the ngout2 values" ){
      THEN( "the returned class has the correct tape value" ){
        for( auto ngout2 : {-23, 23, 50, 99, -99} ){
          iRecordStream<char> issNgout2( 
              std::istringstream(std::to_string( ngout2 ) ) );
          REQUIRE( ngout2 == argument::extract< GROUPR::Card1::Ngout2 >(
                            issNgout2, nendf, npend, ngend ).value );
        }
      }
    }
    WHEN( "the npend, nendf, or ngend value and ngout2 values are the same" ){
      THEN( "an exception is thrown" ){
        int ngout2 = 23;
        ngend.value = ngout2;
        iRecordStream<char> issNgout2( 
            std::istringstream(std::to_string( ngout2 ) ) );
        REQUIRE_THROWS( argument::extract< GROUPR::Card1::Ngout2 >(
                          issNgout2, nendf, npend, ngend ) );

        ngend.value = 22;
        nendf.value = ngout2;
        REQUIRE_THROWS( argument::extract< GROUPR::Card1::Ngout2 >(
                          issNgout2, nendf, npend, ngend ) );

        nendf.value = 20;
        npend.value = ngout2;
        REQUIRE_THROWS( argument::extract< GROUPR::Card1::Ngout2 >(
                          issNgout2, nendf, npend, ngend ) );

      }
    }
  }
  GIVEN( "Invalid ngout2 values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    for( auto ngout2 : invalidValues ){
      iRecordStream<char> issNgout2(
          std::istringstream( std::to_string(ngout2) ) );
      REQUIRE_THROWS(argument::extract<GROUPR::Card1::Npend>(
              issNgout2, nendf));
    }
  }
}

