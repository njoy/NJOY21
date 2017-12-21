#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card6 Ngrp",
          "[MATXSR], [Card6], [Ngrp]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::vector< std::string > validValues{
        "0",
        "0 5",
        "0 5 10",
        "0 5 10 20" };
      for( unsigned int i = 0; i < validValues.size(); i++ ){
        iRecordStream<char> iss( std::istringstream( validValues.at(i) ) );

        THEN( "the value can be verified" ){
          REQUIRE( 0 == argument::extract< MATXSR::Card6::Ngrp >
                                     ( iss, i+1 ).value.at(0) );
          if( i >= 1 ) REQUIRE( 5 == argument::extract< MATXSR::Card6::Ngrp >
                                     ( iss, i+1 ).value.at(1) );
          if( i >= 2 ) REQUIRE( 10 == argument::extract< MATXSR::Card6::Ngrp >
                                      ( iss, i+1 ).value.at(2) );
          if( i >= 3 ) REQUIRE( 20 == argument::extract< MATXSR::Card6::Ngrp >
                                      ( iss, i+1 ).value.at(3) );
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
