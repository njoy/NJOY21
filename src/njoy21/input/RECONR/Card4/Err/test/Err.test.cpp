#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "err input values",
         "[Card4], [Err]"){
  GIVEN( "valid err values" ){
    std::vector<double> validErr{0.1, 1.0, 1E6};

    THEN( "the returned class has the correct value" ){
      for( auto err : validErr ){
        long ln(0);
        std::istringstream issErr(std::to_string(err));
        REQUIRE(err == argument::extract<
                       RECONR::Card4::Err >(issErr, ln).value );
      }
    }
  }
//RECONR::Card4::Err err;

//REQUIRE( err.verify(0.1) );
//REQUIRE( err.verify(1.0) );
//REQUIRE( err.verify(1E6) );
//REQUIRE( not err.verify(0.0) );

//REQUIRE( "err" == err.name() );
} 
