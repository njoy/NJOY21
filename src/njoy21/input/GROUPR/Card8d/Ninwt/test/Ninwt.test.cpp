#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ninwt output values", "[GROUPR],[Card8d], [Ninwt]"){
  Argument< GROUPR::Card1::Nendf > nendf;
  Argument< GROUPR::Card1::Npend > npend;
  Argument< GROUPR::Card1::Ngout1 > ngout1;
  Argument< GROUPR::Card1::Ngout2 > ngout2;
  nendf.value = 40;
  npend.value = 21;
  ngout1.value = 22;
  ngout2.value = 23;

  GIVEN( "valid Ninwt parameters" ){

    THEN( "the returned class has the correct value" ){
      for( auto ninwt : {-20, 20, 50, 99, -99} ){
        iRecordStream<char> issNinwt( 
            std::istringstream( std::to_string( ninwt ) ) );

        REQUIRE( ninwt == argument::extract< GROUPR::Card8d::Ninwt >( 
                          issNinwt, nendf, npend, ngout1, ngout2 ).value );
      }
    }
  } // GIVEN
  GIVEN( "no ninwt value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0 == argument::extract< GROUPR::Card8d::Ninwt >( 
                      iss, nendf, npend, ngout1, ngout2 ).value );
    }
  }
  GIVEN( "invalid Ninwt parameters" ){
    WHEN( "parameters are simply invalid" ){
      std::vector<int> invalidValues{-19, 19, 100, -100};

      THEN( "an exception is thrown" ){
        for( auto ninwt : invalidValues ){
          njoy::Log::debug("ninwt: {}", ninwt);
          iRecordStream<char> issNinwt( 
              std::istringstream( std::to_string( ninwt ) ) );

          REQUIRE_THROWS( argument::extract< GROUPR::Card8d::Ninwt >( 
                  issNinwt, nendf, npend, ngout1, ngout2) );
        }
      }
    }

    WHEN( "ninwt has the same value as nendf, npend, ngout1, or ngout2" ){
      THEN( "an exception is thrown" ){
      }
    }
  } // GIVEN
} // SCENARIO
