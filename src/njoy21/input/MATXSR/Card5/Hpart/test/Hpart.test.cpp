#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MATXSR Card5 hpart",
          "[MATXSR], [Card5], [Hpart]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      std::vector< std::string > validValues{
        "''",
        "'' '12345'",
        "'' '12345' '12345678'" };
      for( unsigned int i = 0; i < validValues.size(); i++ ){
        iRecordStream<char> iss( std::istringstream( validValues.at(i) ) );

        THEN( "the value is verified" ){
          REQUIRE( "''" == argument::extract< MATXSR::Card5::Hpart >
                         ( iss, i+1 ).value.at(0) );
          if( i >= 1 ) REQUIRE( "12345" == 
                                argument::extract< MATXSR::Card5::Hpart >
                                ( iss, i+1 ).value.at(1) );
          if( i >= 2 ) REQUIRE( "12345678" == 
                                argument::extract< MATXSR::Card5::Hpart >
                                ( iss, i+1 ).value.at(2) );
        }
      }
    }
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card5::Hpart >( iss, 1 ) );
      }
    }

    WHEN( "the provided value is invalid" ){
      iRecordStream<char> iss( std::istringstream( "'123456789'" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< MATXSR::Card5::Hpart >( iss, 1 ) );
      }
    }
  } // GIVEN
} // SCENARIO
