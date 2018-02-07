#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3, Card8, Yield",
          "[POWR] [Lib3] [Card8] [Yield]" ){
  GIVEN( "valid inputs" ){
    WHEN( "a valid vector is provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 1.0 1.1/" ) );

      THEN( "the values can be verified" ){
        auto test = argument::extract< POWR::Lib3::Card8::Yield >(iss, 4).value;

        REQUIRE( test.size() == 4 );

        REQUIRE( Approx( 0.0 ) == test.at(0) );
        REQUIRE( Approx( 0.1 ) == test.at(1) );
        REQUIRE( Approx( 1.0 ) == test.at(2) );
        REQUIRE( Approx( 1.1 ) == test.at(3) );
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( std::vector<double>( 6, 0.0 ) == argument::extract<
                                   POWR::Lib3::Card8::Yield >( iss, 6 ).value );
      }
    } // WHEN

    WHEN( "fewer values than expected are provided" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 1.0 /" ) );

      THEN( "the inputs are ignored and the default is used" ){
        auto test = argument::extract< POWR::Lib3::Card8::Yield >(iss, 4).value;

        REQUIRE( test.size() == 4 );

        REQUIRE( std::vector<double>( 4, 0.0 ) == test );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "an invalid value is included" ){
      iRecordStream<char> iss( std::istringstream( " 0.0 0.1 -1.0 1.0/" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< POWR::Lib3::Card8::Yield >(iss, 4) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
