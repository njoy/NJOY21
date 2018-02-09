#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, CISOTX",
          "[CCCCR] [CISOTX]" ){
  const int ngroup = 10;
  const int niso = 4;
  GIVEN( "valid inputs" ){
    WHEN( "valid input with ichix <= 0 is provided" ){
      std::string inp(
 std::string( " 1 0 8 0 /\n" ) +
 std::string( " 123 201.0 12.0 13.0 14.0 15.0 16.0 /\n" ) +
 std::string( " 223 301.0 22.0 23.0 24.0 25.0 26.0 /\n" ) +
 std::string( " 323 401.0 32.0 33.0 34.0 35.0 36.0 /\n" ) +
 std::string( " 423 501.0 42.0 43.0 44.0 45.0 46.0 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR::CISOTX cisotx( iss, ngroup, niso );

        REQUIRE( 1 == cisotx.card1.nsblok.value );
        REQUIRE( 0 == cisotx.card1.maxup.value );
        REQUIRE( 8 == cisotx.card1.maxdn.value );
        REQUIRE( 0 == cisotx.card1.ichix.value );

        REQUIRE( std::nullopt == cisotx.card2 );
        REQUIRE( std::nullopt == cisotx.card3 );

        REQUIRE( 4 == cisotx.card4.size() );

        REQUIRE( 123 == cisotx.card4.at(0).kbr.value );
        REQUIRE( 201.0*dimwits::gram == cisotx.card4.at(0).amass.value );
        REQUIRE( Approx( 12.0 ) == cisotx.card4.at(0).efiss.value );
        REQUIRE( Approx( 13.0 ) == cisotx.card4.at(0).ecapt.value );
        REQUIRE( 14.0*dimwits::kelvin == cisotx.card4.at(0).temp.value );
        REQUIRE( Approx( 15.0 ) == cisotx.card4.at(0).sigpot.value );
        REQUIRE( Approx( 16.0 ) == cisotx.card4.at(0).adens.value.value );

        REQUIRE( 223 == cisotx.card4.at(1).kbr.value );
        REQUIRE( 301.0*dimwits::gram == cisotx.card4.at(1).amass.value );
        REQUIRE( Approx( 22.0 ) == cisotx.card4.at(1).efiss.value );
        REQUIRE( Approx( 23.0 ) == cisotx.card4.at(1).ecapt.value );
        REQUIRE( 24.0*dimwits::kelvin == cisotx.card4.at(1).temp.value );
        REQUIRE( Approx( 25.0 ) == cisotx.card4.at(1).sigpot.value );
        REQUIRE( Approx( 26.0 ) == cisotx.card4.at(1).adens.value.value );

        REQUIRE( 323 == cisotx.card4.at(2).kbr.value );
        REQUIRE( 401.0*dimwits::gram == cisotx.card4.at(2).amass.value );
        REQUIRE( Approx( 32.0 ) == cisotx.card4.at(2).efiss.value );
        REQUIRE( Approx( 33.0 ) == cisotx.card4.at(2).ecapt.value );
        REQUIRE( 34.0*dimwits::kelvin == cisotx.card4.at(2).temp.value );
        REQUIRE( Approx( 35.0 ) == cisotx.card4.at(2).sigpot.value );
        REQUIRE( Approx( 36.0 ) == cisotx.card4.at(2).adens.value.value );

        REQUIRE( 423 == cisotx.card4.at(3).kbr.value );
        REQUIRE( 501.0*dimwits::gram == cisotx.card4.at(3).amass.value );
        REQUIRE( Approx( 42.0 ) == cisotx.card4.at(3).efiss.value );
        REQUIRE( Approx( 43.0 ) == cisotx.card4.at(3).ecapt.value );
        REQUIRE( 44.0*dimwits::kelvin == cisotx.card4.at(3).temp.value );
        REQUIRE( Approx( 45.0 ) == cisotx.card4.at(3).sigpot.value );
        REQUIRE( Approx( 46.0 ) == cisotx.card4.at(3).adens.value.value );
      }
    } // WHEN

    WHEN( "valid values with ichix = 1" ){
      std::string inp(
 std::string( " 10 0 1 1 /\n" ) +
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 /\n" ) +
 std::string( " 123 201.0 12.0 13.0 14.0 15.0 16.0 /\n" ) +
 std::string( " 223 301.0 22.0 23.0 24.0 25.0 26.0 /\n" ) +
 std::string( " 323 401.0 32.0 33.0 34.0 35.0 36.0 /\n" ) +
 std::string( " 423 501.0 42.0 43.0 44.0 45.0 46.0 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR::CISOTX cisotx( iss, ngroup, niso );

        REQUIRE( 10 == cisotx.card1.nsblok.value );
        REQUIRE( 0 == cisotx.card1.maxup.value );
        REQUIRE( 1 == cisotx.card1.maxdn.value );
        REQUIRE( 1 == cisotx.card1.ichix.value );

        for( int i = 0; i < ngroup; i++ ){
          REQUIRE( Approx( i*0.1 ) == cisotx.card2->spec.value.at( i ) );
        }

        REQUIRE( std::nullopt == cisotx.card3 );

        REQUIRE( 4 == cisotx.card4.size() );

        REQUIRE( 123 == cisotx.card4.at(0).kbr.value );
        REQUIRE( 201.0*dimwits::gram == cisotx.card4.at(0).amass.value );
        REQUIRE( Approx( 12.0 ) == cisotx.card4.at(0).efiss.value );
        REQUIRE( Approx( 13.0 ) == cisotx.card4.at(0).ecapt.value );
        REQUIRE( 14.0*dimwits::kelvin == cisotx.card4.at(0).temp.value );
        REQUIRE( Approx( 15.0 ) == cisotx.card4.at(0).sigpot.value );
        REQUIRE( Approx( 16.0 ) == cisotx.card4.at(0).adens.value.value );

        REQUIRE( 223 == cisotx.card4.at(1).kbr.value );
        REQUIRE( 301.0*dimwits::gram == cisotx.card4.at(1).amass.value );
        REQUIRE( Approx( 22.0 ) == cisotx.card4.at(1).efiss.value );
        REQUIRE( Approx( 23.0 ) == cisotx.card4.at(1).ecapt.value );
        REQUIRE( 24.0*dimwits::kelvin == cisotx.card4.at(1).temp.value );
        REQUIRE( Approx( 25.0 ) == cisotx.card4.at(1).sigpot.value );
        REQUIRE( Approx( 26.0 ) == cisotx.card4.at(1).adens.value.value );

        REQUIRE( 323 == cisotx.card4.at(2).kbr.value );
        REQUIRE( 401.0*dimwits::gram == cisotx.card4.at(2).amass.value );
        REQUIRE( Approx( 32.0 ) == cisotx.card4.at(2).efiss.value );
        REQUIRE( Approx( 33.0 ) == cisotx.card4.at(2).ecapt.value );
        REQUIRE( 34.0*dimwits::kelvin == cisotx.card4.at(2).temp.value );
        REQUIRE( Approx( 35.0 ) == cisotx.card4.at(2).sigpot.value );
        REQUIRE( Approx( 36.0 ) == cisotx.card4.at(2).adens.value.value );

        REQUIRE( 423 == cisotx.card4.at(3).kbr.value );
        REQUIRE( 501.0*dimwits::gram == cisotx.card4.at(3).amass.value );
        REQUIRE( Approx( 42.0 ) == cisotx.card4.at(3).efiss.value );
        REQUIRE( Approx( 43.0 ) == cisotx.card4.at(3).ecapt.value );
        REQUIRE( 44.0*dimwits::kelvin == cisotx.card4.at(3).temp.value );
        REQUIRE( Approx( 45.0 ) == cisotx.card4.at(3).sigpot.value );
        REQUIRE( Approx( 46.0 ) == cisotx.card4.at(3).adens.value.value );
      }
    } // WHEN

    WHEN( "a valid input with ichix > 1 is provided" ){
      std::string inp(
 std::string( " 10 0 1 3 /\n" ) +
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 \n" ) +
 std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 \n" ) +
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 /\n" ) +
 std::string( " 123 201.0 12.0 13.0 14.0 15.0 16.0 /\n" ) +
 std::string( " 223 301.0 22.0 23.0 24.0 25.0 26.0 /\n" ) +
 std::string( " 323 401.0 32.0 33.0 34.0 35.0 36.0 /\n" ) +
 std::string( " 423 501.0 42.0 43.0 44.0 45.0 46.0 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        CCCCR::CISOTX cisotx( iss, ngroup, niso );

        REQUIRE( 10 == cisotx.card1.nsblok.value );
        REQUIRE( 0 == cisotx.card1.maxup.value );
        REQUIRE( 1 == cisotx.card1.maxdn.value );
        REQUIRE( 3 == cisotx.card1.ichix.value );

        REQUIRE( std::nullopt == cisotx.card2 );

        for( int i = 0; i < cisotx.card1.ichix.value; i++ ){
          for( int j = 0; j < ngroup; j++ ){
            REQUIRE( Approx( i*1.0 + j*0.1 ) ==
                                     cisotx.card3->spec.value.at( i ).at( j ) );
          }
        }

        REQUIRE( 4 == cisotx.card4.size() );

        REQUIRE( 123 == cisotx.card4.at(0).kbr.value );
        REQUIRE( 201.0*dimwits::gram == cisotx.card4.at(0).amass.value );
        REQUIRE( Approx( 12.0 ) == cisotx.card4.at(0).efiss.value );
        REQUIRE( Approx( 13.0 ) == cisotx.card4.at(0).ecapt.value );
        REQUIRE( 14.0*dimwits::kelvin == cisotx.card4.at(0).temp.value );
        REQUIRE( Approx( 15.0 ) == cisotx.card4.at(0).sigpot.value );
        REQUIRE( Approx( 16.0 ) == cisotx.card4.at(0).adens.value.value );

        REQUIRE( 223 == cisotx.card4.at(1).kbr.value );
        REQUIRE( 301.0*dimwits::gram == cisotx.card4.at(1).amass.value );
        REQUIRE( Approx( 22.0 ) == cisotx.card4.at(1).efiss.value );
        REQUIRE( Approx( 23.0 ) == cisotx.card4.at(1).ecapt.value );
        REQUIRE( 24.0*dimwits::kelvin == cisotx.card4.at(1).temp.value );
        REQUIRE( Approx( 25.0 ) == cisotx.card4.at(1).sigpot.value );
        REQUIRE( Approx( 26.0 ) == cisotx.card4.at(1).adens.value.value );

        REQUIRE( 323 == cisotx.card4.at(2).kbr.value );
        REQUIRE( 401.0*dimwits::gram == cisotx.card4.at(2).amass.value );
        REQUIRE( Approx( 32.0 ) == cisotx.card4.at(2).efiss.value );
        REQUIRE( Approx( 33.0 ) == cisotx.card4.at(2).ecapt.value );
        REQUIRE( 34.0*dimwits::kelvin == cisotx.card4.at(2).temp.value );
        REQUIRE( Approx( 35.0 ) == cisotx.card4.at(2).sigpot.value );
        REQUIRE( Approx( 36.0 ) == cisotx.card4.at(2).adens.value.value );

        REQUIRE( 423 == cisotx.card4.at(3).kbr.value );
        REQUIRE( 501.0*dimwits::gram == cisotx.card4.at(3).amass.value );
        REQUIRE( Approx( 42.0 ) == cisotx.card4.at(3).efiss.value );
        REQUIRE( Approx( 43.0 ) == cisotx.card4.at(3).ecapt.value );
        REQUIRE( 44.0*dimwits::kelvin == cisotx.card4.at(3).temp.value );
        REQUIRE( Approx( 45.0 ) == cisotx.card4.at(3).sigpot.value );
        REQUIRE( Approx( 46.0 ) == cisotx.card4.at(3).adens.value.value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX( iss, ngroup, niso ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      std::string inp(
 std::string( " 1 1 8 0 /\n" ) +
 std::string( " 123 201.0 12.0 13.0 14.0 15.0 16.0 /\n" ) +
 std::string( " 223 301.0 22.0 23.0 24.0 25.0 26.0 /\n" ) +
 std::string( " 323 401.0 32.0 33.0 34.0 35.0 36.0 /\n" ) +
 std::string( " 423 501.0 42.0 43.0 44.0 45.0 46.0 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( CCCCR::CISOTX( iss, ngroup, niso ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
