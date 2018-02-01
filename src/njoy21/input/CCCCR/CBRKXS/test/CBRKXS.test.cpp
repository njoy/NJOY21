#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CBRKXS",
          "[CCCCR] [CBRKXS]" ){
  GIVEN( "valid inputs" ){
    WHEN( "nti and nzi are < 0" ){
      iRecordStream<char> iss( std::istringstream( " -1 -2 /" ) );

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS cbrkxs( iss );

        REQUIRE( -1 == cbrkxs.card1.nti.value );
        REQUIRE( -2 == cbrkxs.card1.nzi.value );

        REQUIRE( std::nullopt == cbrkxs.card2 );
        REQUIRE( std::nullopt == cbrkxs.card3 );
      }
    } // WHEN

    WHEN( "nti is > 0 but nzi is < 0" ){
      std::string inp(
 std::string( " 5 -4 /\n" ) +
 std::string( " 0.1 0.2 0.3 0.4 0.5 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS cbrkxs( iss );

        REQUIRE( 5 == cbrkxs.card1.nti.value );
        REQUIRE( -4 == cbrkxs.card1.nzi.value );

        REQUIRE( 0.1*dimwits::kelvin == cbrkxs.card2->atem.value.at( 0 ) );
        REQUIRE( 0.2*dimwits::kelvin == cbrkxs.card2->atem.value.at( 1 ) );
        REQUIRE( 0.3*dimwits::kelvin == cbrkxs.card2->atem.value.at( 2 ) );
        REQUIRE( 0.4*dimwits::kelvin == cbrkxs.card2->atem.value.at( 3 ) );
        REQUIRE( 0.5*dimwits::kelvin == cbrkxs.card2->atem.value.at( 4 ) );

        REQUIRE( std::nullopt == cbrkxs.card3 );
      }
    } // WHEN

    WHEN( "nzi is > 0 but nti is < 0" ){
      std::string inp(
 std::string( " -5 4 /\n" ) +
 std::string( " 0.1 0.2 0.3 0.4 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS cbrkxs( iss );

        REQUIRE( -5 == cbrkxs.card1.nti.value );
        REQUIRE( 4 == cbrkxs.card1.nzi.value );

        REQUIRE( std::nullopt == cbrkxs.card2 );

        REQUIRE( Approx( 0.1 ) == cbrkxs.card3->asig.value.at( 0 ) );
        REQUIRE( Approx( 0.2 ) == cbrkxs.card3->asig.value.at( 1 ) );
        REQUIRE( Approx( 0.3 ) == cbrkxs.card3->asig.value.at( 2 ) );
        REQUIRE( Approx( 0.4 ) == cbrkxs.card3->asig.value.at( 3 ) );
      }
    } // WHEN

    WHEN( "both are > 0" ){
      std::string inp(
 std::string( " 5 4 /\n" ) +
 std::string( " 0.1 0.2 0.3 0.4 0.5 /\n" ) +
 std::string( " 1.0 1.1 1.2 1.3 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR::CBRKXS cbrkxs( iss );

        REQUIRE( 5 == cbrkxs.card1.nti.value );
        REQUIRE( 4 == cbrkxs.card1.nzi.value );

        REQUIRE( 0.1*dimwits::kelvin == cbrkxs.card2->atem.value.at( 0 ) );
        REQUIRE( 0.2*dimwits::kelvin == cbrkxs.card2->atem.value.at( 1 ) );
        REQUIRE( 0.3*dimwits::kelvin == cbrkxs.card2->atem.value.at( 2 ) );
        REQUIRE( 0.4*dimwits::kelvin == cbrkxs.card2->atem.value.at( 3 ) );
        REQUIRE( 0.5*dimwits::kelvin == cbrkxs.card2->atem.value.at( 4 ) );

        REQUIRE( Approx( 1.0 ) == cbrkxs.card3->asig.value.at( 0 ) );
        REQUIRE( Approx( 1.1 ) == cbrkxs.card3->asig.value.at( 1 ) );
        REQUIRE( Approx( 1.2 ) == cbrkxs.card3->asig.value.at( 2 ) );
        REQUIRE( Approx( 1.3 ) == cbrkxs.card3->asig.value.at( 3 ) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS( iss ) );
      }
    } // WHEN

    WHEN( "the temperatures and sigpots are swapped" ){
      std::string inp(
 std::string( " 4 5 /\n" ) +
 std::string( " 0.1 0.2 0.3 0.4 0.5 /\n" ) +
 std::string( " 1.0 1.1 1.2 1.3 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS( iss ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      std::string inp(
 std::string( " 5 4 /\n" ) +
 std::string( " 0.1 0.2 -0.3 0.4 0.5 /\n" ) +
 std::string( " 1.0 1.1 1.2 1.3 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CBRKXS( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
