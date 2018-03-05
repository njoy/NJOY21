#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card6 Ngrp",
          "[MATXSR], [Card6], [Ngrp]" ){
  GIVEN( "valid inputs" ){
    std::vector< std::string > validValues{
      "0",
      "0 5",
      "0 5 10",
      "0 5 10 20" };
    for( unsigned int i = 0; i < validValues.size(); i++ ){
      std::string situ( "valid input " + validValues.at(i) + " is provided." );
      WHEN( situ.c_str() ){
        iRecordStream<char> iss( std::istringstream( validValues.at(i) ) );

        THEN( "the value can be verified" ){
          auto res = argument::extract< MATXSR::Card6::Ngrp >( iss, i+1 ).value;
          REQUIRE( 0 == res.at(0) );
          if( i >= 1 ) REQUIRE( 5 == res.at(1) );
          if( i >= 2 ) REQUIRE( 10 == res.at(2) );
          if( i >= 3 ) REQUIRE( 20 == res.at(3) );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card6::Ngrp >( iss, 1 ) );
      }
    }

    WHEN( "an invalid value is provided" ){
      iRecordStream<char> iss( std::istringstream( std::to_string( -1 ) ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card6::Ngrp >( iss, 1 ) );
      }
    }
  } // GIVEN
} // SCENARIO
