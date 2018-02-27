#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "ERRORR, Normal, Card12b, Egn",
          "[ERRORR] [Normal] [Card12b] [Egn]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid input is provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e-6 5e-5 2e-2 1e1 /" ) );

      THEN( "the values can be verified" ){
        auto egn =
              argument::extract< ERRORR::Normal::Card12b::Egn >( iss, 4 ).value;

        REQUIRE( 4 == egn.size() );

        REQUIRE( 1e-6*dimwits::electronVolt == egn.at(0) );
        REQUIRE( 5e-5*dimwits::electronVolt == egn.at(1) );
        REQUIRE( 2e-2*dimwits::electronVolt == egn.at(2) );
        REQUIRE( 1e1*dimwits::electronVolt == egn.at(3) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "a negative value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -1e-6 5e-5 2e-2 1e1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card12b::Egn >(
                                                                     iss, 4 ) );
      }
    } // WHEN

    WHEN( "the values are not in ascending order" ){
      iRecordStream<char> iss( std::istringstream( " 1e-6 2e-2 5e-5 1e1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card12b::Egn >(
                                                                     iss, 4 ) );
      }
    } // WHEN

    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card12b::Egn >(
                                                                     iss, 0 ) );
      }
    } // WHEN

    WHEN( "fewer values than expected are provided" ){
      iRecordStream<char> iss( std::istringstream( " 1e-6 5e-5 2e-2 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< ERRORR::Normal::Card12b::Egn >(
                                                                     iss, 4 ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
