#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Ninwt output values", "[GROUPR],[Card8a], [Ninwt]"){
  iRecordStream<char> issCard1( std::istringstream("40 21 22 23 / " ) );
  GROUPR::Card1 card1(issCard1);

  GIVEN( "valid Ninwt parameters" ){
    THEN( "the returned class has the correct value" ){
      for( auto ninwt : {-20, 20, 50, 99, -99} ){
        iRecordStream<char> issNinwt( 
            std::istringstream( std::to_string( ninwt ) ) );

        REQUIRE( ninwt == argument::extract< GROUPR::Card8a::Ninwt >( 
                          issNinwt, card1 ).value );
      }
    }
  } // GIVEN
  GIVEN( "no ninwt value" ){
    THEN( "the default value is returned" ){
      iRecordStream<char> iss( std::istringstream( "/") );
      REQUIRE( 0 == argument::extract< GROUPR::Card8a::Ninwt >( 
                      iss, card1 ).value );
    }
    WHEN( "a card1 parameter also has a value of 0" ){
      iRecordStream<char> issCard2( std::istringstream("40 21 22 23 / " ) );
      card1 = GROUPR::Card1(issCard2);
      THEN( "the default value is returned" ){
        iRecordStream<char> iss( std::istringstream( "/") );
        REQUIRE( 0 == argument::extract< GROUPR::Card8a::Ninwt >( 
                        iss, card1 ).value );
      }
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

          REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Ninwt >( 
                  issNinwt, card1 ) );
        }
      }
    }

    WHEN( "ninwt has the same value as nendf, npend, ngout1, or ngout2" ){
      THEN( "an exception is thrown" ){
        for( auto ninwt : {40, 21, 22, 23} ){
          njoy::Log::debug("ninwt: {}", ninwt);
          iRecordStream<char> issNinwt( 
              std::istringstream( std::to_string( ninwt ) ) );

          REQUIRE_THROWS( argument::extract< GROUPR::Card8a::Ninwt >( 
                  issNinwt, card1 ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
