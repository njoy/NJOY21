#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "errmax input values", "[Card4], [Errmax]"){
  GIVEN( "valid err values" ){
    Argument< RECONR::Card4::Err > err;
    err.value = 0.01;
    RECONR::Card4::Errmax errmax;
    WHEN( "the errmax values are valid" ){
      std::vector<double> validErrmax{0.01, 0.2};
      THEN( "the returned class has the correct value" ){
        for( auto errmax : validErrmax ){
          iRecordStream<char> iss( std::istringstream( std::to_string(errmax) ) );
          auto errMaxArg = argument::extract< RECONR::Card4::Errmax >(iss, err);
          REQUIRE( errmax == errMaxArg.value );
        }
      }
    }
    WHEN( "the errmax values are invalid" ){
      double errmax(0.002);
      THEN( "an exception is thrown" ){
        iRecordStream<char> iss( std::istringstream( std::to_string(errmax) ) );
        REQUIRE_THROWS( argument::extract< RECONR::Card4::Errmax >(iss, err) );
      }
    }
  }
}
