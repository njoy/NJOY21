#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "MIXR, Card3",
          "[MIXR] [Card3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "valid values are provided" ){
      std::string inp(
 " 816 0.2 /\n"
 " 9235 0.3 /\n"
 " 9439 0.5 /\n"
      );
      iRecordStream<char> iss{ std::istringstream{ inp } };
      const size_t nnin = 3;

      THEN( "the values can be verified" ){
        MIXR::Card3 card3( iss, nnin );

        REQUIRE( 3 == card3.matnWtnList.size() );

        REQUIRE( 816 == card3.matnWtnList.at( 0 ).first.value );
        REQUIRE( Approx( 0.2 ) == card3.matnWtnList.at( 0 ).second.value );

        REQUIRE( 9235 == card3.matnWtnList.at( 1 ).first.value );
        REQUIRE( Approx( 0.3 ) == card3.matnWtnList.at( 1 ).second.value );

        REQUIRE( 9439 == card3.matnWtnList.at( 2 ).first.value );
        REQUIRE( Approx( 0.5 ) == card3.matnWtnList.at( 2 ).second.value );
      }
    } // WHEN

    WHEN( "the maximum number of values are provided" ){
      std::string inp(
 " 1 0.1 /\n"
 " 2 0.2 /\n"
 " 3 0.3 /\n"
 " 4 0.4 /\n"
 " 5 0.5 /\n"
 " 6 0.6 /\n"
 " 7 0.7 /\n"
 " 8 0.8 /\n"
 " 9 0.9 /\n"
 " 10 1.0 /\n"
      );
      iRecordStream<char> iss{ std::istringstream{ inp } };

      const size_t nnin = 10;

      THEN( "the values can be verified" ){
        MIXR::Card3 card3( iss, nnin );

        for( int i = 0; i < 10; i++ ){
          REQUIRE( ( i + 1 ) == card3.matnWtnList.at( i ).first.value );
          REQUIRE( Approx( ( i+1 ) * 0.1 ) ==
                                       card3.matnWtnList.at( i ).second.value );
        }
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no values are provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );
      const size_t nnin = 1;

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss, nnin ) );
      }
    } // WHEN

    WHEN( "too many values are provided" ){
      std::string inp(
 " 1 0.1 /\n"
 " 2 0.2 /\n"
 " 3 0.3 /\n"
 " 4 0.4 /\n"
 " 5 0.5 /\n"
 " 6 0.6 /\n"
 " 7 0.7 /\n"
 " 8 0.8 /\n"
 " 9 0.9 /\n"
 " 10 1.0 /\n"
 " 11 1.1 /\n"
      );
      iRecordStream<char> iss{ std::istringstream{ inp } };
      const size_t nnin = 11;

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss, nnin ) );
      }
    } // WHEN

    WHEN( "an invalid value is provided" ){
      std::string inp(
 " 1 0.2 /\n"
 " 2 0.3 /\n"
 " 3 1.1 /\n"
      );
      iRecordStream<char> iss{ std::istringstream{ inp } };
      const size_t nnin = 3;

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss, nnin ) );
      }
    } // WHEN

    WHEN( "a material number is used more than once" ){
      std::string inp(
 " 1 0.1 /\n"
 " 2 0.2 /\n"
 " 1 0.3 /\n"
      );
      iRecordStream<char> iss{ std::istringstream{ inp } };
      const size_t nnin = 3;

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( MIXR::Card3( iss, nnin ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
