#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 24;
  Argument< GAMINR::Card1::Npend > npend; npend.value = 28;
  Argument< GAMINR::Card1::Ngam1 > ngam1; ngam1.value = 30;
  GIVEN( "valid ngam2 input" ){
    WHEN( "all values are valid" ){
      for( auto ngam2 : {0, 20, 99, 59} ){
        iRecordStream<char> issNgam2(
            std::istringstream( std::to_string(ngam2) ) );
        REQUIRE( ngam2 == argument::extract< GAMINR::Card1::Ngam2 >(
                          issNgam2, nendf, npend, ngam1 ).value );
      }
      nendf.value *= -1;
      ngam1.value *= -1;
      for( auto ngam2 : {-20, -99, -59} ){
        iRecordStream<char> issNgam2(
            std::istringstream( std::to_string(ngam2) ) );
        REQUIRE( ngam2 == argument::extract< GAMINR::Card1::Ngam2 >(
                          issNgam2, nendf, npend, ngam1 ).value );
      }
    }
  } // GIVEN
  {
    iRecordStream<char> iss( std::istringstream(" /") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( 
                       iss, nendf, npend, ngam1 ).value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream(" -0") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( 
                       iss, nendf, npend, ngam1 ).value == 0 );
  }
}

SCENARIO( "expected failures" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 24;
  Argument< GAMINR::Card1::Npend > npend; npend.value = 28;
  Argument< GAMINR::Card1::Ngam1 > ngam1; ngam1.value = 30;
  GIVEN( "invalid ngam2 input" ){
    WHEN( "invalid values for ngam2" ){
      for( auto ngam2 : {19, 100} ){
        iRecordStream<char> issNgam2(
            std::istringstream( std::to_string(ngam2) ) );
        REQUIRE_THROWS( argument::extract< GAMINR::Card1::Ngam2 >(
                          issNgam2, nendf, npend, ngam1 ) );
      }
      nendf.value *= -1;
      for( auto ngam2 : {-19, -100} ){
        iRecordStream<char> issNgam2(
            std::istringstream( std::to_string(ngam2) ) );
        REQUIRE_THROWS( argument::extract< GAMINR::Card1::Ngam2 >(
                          issNgam2, nendf, npend, ngam1 ) );
      }
    }
  } // GIVEN
  {
    iRecordStream<char> iss( std::istringstream(" cat") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
    iRecordStream<char> iss( std::istringstream("    ") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream("  24") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
    iRecordStream<char> iss( std::istringstream("  28") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -29") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }
}
