#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib1",
          "[POWR] [Lib1]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a material value of zero is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0 /" ) );

      THEN( "the value can be verified and the rest are unused" ){
        POWR::Lib1 lib1( iss );

        REQUIRE( 0 == lib1.card3.matd.value );
        REQUIRE( std::nullopt == lib1.card3.rest );
        REQUIRE( std::nullopt == lib1.card45 );
        REQUIRE( std::nullopt == lib1.card6 );
      }
    } // WHEN

    WHEN( "a negative material value is provided" ){
      iRecordStream<char> iss( std::istringstream( " -9439 /" ) );

      THEN( "the value can be verified and the rest are unused" ){
        POWR::Lib1 lib1( iss );

        REQUIRE( -9439 == lib1.card3.matd.value );
        REQUIRE( std::nullopt == lib1.card3.rest );
        REQUIRE( std::nullopt == lib1.card45 );
        REQUIRE( std::nullopt == lib1.card6 );
      }
    } // WHEN

    WHEN( "a positive material value is provided with the rest defaulted" ){
      std::string inp(
 std::string( " 9439 /\n" ) +
 std::string( " /\n" ) +
 std::string( " /\n" ) +
 std::string( " /\n" )
      );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the value and default values can be verified" ){
        POWR::Lib1 lib1( iss );

        REQUIRE( 9439 == lib1.card3.matd.value );
        REQUIRE( 300.0*dimwits::kelvin ==
                                    std::get<0>( *( lib1.card3.rest ) ).value );
        REQUIRE( 1 == std::get<1>( *( lib1.card3.rest ) ).value );
        REQUIRE( 0 == std::get<2>( *( lib1.card3.rest ) ).value );
        REQUIRE( 1 == std::get<3>( *( lib1.card3.rest ) ).value );

        REQUIRE( "" == lib1.card45->first.word.value );

        REQUIRE( "" == lib1.card45->second.fsn.value );

        REQUIRE( std::vector<double>( 68, 0.0 ) == lib1.card6->abs.value );
      }
    } // WHEN

    WHEN( "all values are specified" ){
      std::string inp(
 std::string( " 9439 279.0 0 2 2 /\n" ) +
 std::string( " 'word value' /\n" ) +
 std::string( " 'fsn value' /\n" ) +
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9\n" ) +
 std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9\n" ) +
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9\n" ) +
 std::string( " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9\n" ) +
 std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9\n" ) +
 std::string( " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9\n" ) +
 std::string( " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        POWR::Lib1 lib1( iss );

        REQUIRE( 9439 == lib1.card3.matd.value );
        REQUIRE( 279.0*dimwits::kelvin ==
                                    std::get<0>( *( lib1.card3.rest ) ).value );
        REQUIRE( 0 == std::get<1>( *( lib1.card3.rest ) ).value );
        REQUIRE( 2 == std::get<2>( *( lib1.card3.rest ) ).value );
        REQUIRE( 2 == std::get<3>( *( lib1.card3.rest ) ).value );

        REQUIRE( "word value" == lib1.card45->first.word.value );

        REQUIRE( "fsn value" == lib1.card45->second.fsn.value );

        for( int i = 0; i < 68; i++ ){
          double d( i*0.1 );
          REQUIRE( Approx( d ) == lib1.card6->abs.value.at(i) );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid material is provided" ){
      iRecordStream<char> iss( std::istringstream( " 10000 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1( iss ) );
      }
    } // WHEN

    WHEN( "a positive material is given but nothing else" ){
      iRecordStream<char> iss( std::istringstream( " 9439 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR::Lib1( iss ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
