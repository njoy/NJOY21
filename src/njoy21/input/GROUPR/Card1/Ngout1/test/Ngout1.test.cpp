#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ndir output values", "[GROUPR],[Card1], [Ngout1]"){
  Argument< GROUPR::Card1::Nendf > nendf;
  Argument< GROUPR::Card1::Npend > npend;
  nendf.value = 20;

  GIVEN( "valid ngout1 values" ){
    WHEN( "the nendf and npend values are not the same as the ngout1 values" ){
      npend.value = 21;

      THEN( "the returned class has the correct tape value" ){
        for( auto ngout1 : {-22, 22, 50, 99, -99} ){
          npend.value = 21*( ngout1/std::abs(ngout1) );
          iRecordStream<char> issNgout1( 
              std::istringstream( std::to_string( ngout1 )  ) );
          REQUIRE( ngout1 == argument::extract< GROUPR::Card1::Ngout1 >(
                            issNgout1, nendf, npend ).value );
        }
      }
    }
    WHEN( "the npend or nendf value and ngout1 values are the same" ){
      THEN( "an exception is thrown" ){
        int ngout1 = 22;
        npend.value = ngout1;
        iRecordStream<char> issNgout1( 
            std::istringstream( std::to_string( ngout1 )  ) );
        REQUIRE_THROWS( argument::extract< GROUPR::Card1::Ngout1 >(
                          issNgout1, nendf, npend ) );

        nendf.value = 22;
        npend.value = 21;
        REQUIRE_THROWS( argument::extract< GROUPR::Card1::Ngout1 >(
                          issNgout1, nendf, npend ) );

      }
    }
    WHEN( "no value is given (default)" ){
      iRecordStream<char> issNgout1( std::istringstream( " /" ) );
      npend.value = 21;
      REQUIRE( 0 == argument::extract< GROUPR::Card1::Ngout1 >(
              issNgout1, nendf, npend ).value );
    }
  }
  GIVEN( "Invalid ngout1 values" ){
    std::vector<int> invalidValues{-19, 19, 100, -100};
    for( auto ngout1 : invalidValues ){
      iRecordStream<char> issNgout1(
          std::istringstream( std::to_string(ngout1) ) );
      REQUIRE_THROWS(argument::extract<GROUPR::Card1::Npend>(
              issNgout1, nendf));
    }
  }
}

