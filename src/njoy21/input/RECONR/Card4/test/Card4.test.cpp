#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying RECONR Card4 input", "[Card4]"){
  GIVEN( "valid err" ){
    double err(0.01);

    WHEN( "all the optional parameters are given" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(err) 
						   + " 293.6 1.0 2.0") );
      RECONR::Card4 card4(iss );
      REQUIRE( err == card4.err.value );
      REQUIRE( 293.6 == Approx(card4.tempr.value.value) );
      REQUIRE( 1.0 == card4.errmax.value );
      REQUIRE( 2.0 == Approx(card4.errint.value.value) );

    }
    WHEN( "none of the optional parameters are given" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(err) + '/') );
      RECONR::Card4 card4(iss);

      REQUIRE( err == card4.err.value );
      REQUIRE( 0.0 == Approx(card4.tempr.value.value) );
      REQUIRE( err * 10 == card4.errmax.value );
      REQUIRE( (err / 2E4) == Approx(card4.errint.value.value) );
    }
  }

  GIVEN( "invalid err" ){
    double err(0.0);
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( std::to_string(err) + '/') );
      REQUIRE_THROWS( RECONR::Card4(iss) );
    }
  }
} // SCENARIO

