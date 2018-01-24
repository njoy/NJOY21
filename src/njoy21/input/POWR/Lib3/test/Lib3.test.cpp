#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR, Lib3",
          "[POWR] [Lib3]" ){
  GIVEN( "valid inputs" ){
    WHEN( "the shortest valid input is provided" ){
      std::string inp(
 std::string( " 27 19990101 2 1 1 0 0 /\n" ) +
 std::string( " 1 2 2 0.1 1.0 1.1 0 0 /\n" ) +
 std::string( " 1 2 2 0.1 1.0 1.1 0 0 /\n" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "those values can be verified" ){
        POWR::Lib3 lib3( iss, 1 );

        REQUIRE( 27 == lib3.card3.nlib.value );
        REQUIRE( 19990101 == lib3.card3.idat.value );
        REQUIRE( 2 == lib3.card3.newmat.value );
        REQUIRE( 1 == lib3.card3.iopt.value );
        REQUIRE( 1 == lib3.card3.mode.value );
        REQUIRE( 0 == lib3.card3.if5.value );
        REQUIRE( 0 == lib3.card3.if4.value );

        REQUIRE( std::nullopt == lib3.card4 );

        REQUIRE( 1 == lib3.card5List.at(0).nina.value );
        REQUIRE( 2 == lib3.card5List.at(0).ntemp.value );
        REQUIRE( 2 == lib3.card5List.at(0).nsigz.value );
        REQUIRE( Approx( 0.1 ) == lib3.card5List.at(0).sgref.value );
        REQUIRE( Approx( 1.0 ) == std::get<0>( *( lib3.card5List.at(0).ntapea0 )
                                                                      ).value );
        REQUIRE( Approx( 1.1 ) == std::get<1>( *( lib3.card5List.at(0).ntapea0 )
                                                                      ).value );
        REQUIRE( 0 == std::get<2>( *( lib3.card5List.at(0).ntapea0 ) ).value );
        REQUIRE( 0 == std::get<3>( *( lib3.card5List.at(0).ntapea0 ) ).value );

        REQUIRE( 1 == lib3.card5List.at(1).nina.value );
        REQUIRE( 2 == lib3.card5List.at(1).ntemp.value );
        REQUIRE( 2 == lib3.card5List.at(1).nsigz.value );
        REQUIRE( Approx( 0.1 ) == lib3.card5List.at(1).sgref.value );
        REQUIRE( Approx( 1.0 ) == std::get<0>( *( lib3.card5List.at(0).ntapea0 )
                                                                      ).value );
        REQUIRE( Approx( 1.1 ) == std::get<1>( *( lib3.card5List.at(0).ntapea0 )
                                                                      ).value );
        REQUIRE( 0 == std::get<2>( *( lib3.card5List.at(0).ntapea0 ) ).value );
        REQUIRE( 0 == std::get<3>( *( lib3.card5List.at(0).ntapea0 ) ).value );
      }
    } // WHEN
  } // GIVEN

//  GIVEN( "invalid inputs" ){
//
//  } // GIVEN
} // SCENARIO
