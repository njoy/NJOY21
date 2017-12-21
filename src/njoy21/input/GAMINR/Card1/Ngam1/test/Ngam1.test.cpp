#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 24;
  Argument< GAMINR::Card1::Npend > npend; npend.value = 28;
  GIVEN( "valid ngam1 input" ){
    WHEN( "all values are valid" ){
      for( auto ngam1 : {0, 20, 99, 59} ){
        iRecordStream<char> issNgam1(
            std::istringstream( std::to_string(ngam1) ) );
        REQUIRE( ngam1 == argument::extract< GAMINR::Card1::Ngam1 >(
                          issNgam1, nendf, npend ).value );
      }
      nendf.value *= -1;
      for( auto ngam1 : {-20, -99, -59} ){
        iRecordStream<char> issNgam1(
            std::istringstream( std::to_string(ngam1) ) );
        REQUIRE( ngam1 == argument::extract< GAMINR::Card1::Ngam1 >(
                          issNgam1, nendf, npend ).value );
      }
    }
  } // GIVEN
  {
    iRecordStream<char> iss( std::istringstream(" /") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam1 >( iss, nendf, npend ).value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream(" -0") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam1 >( iss, nendf, npend ).value == 0 );
  }
}

SCENARIO( "expected failures" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 24;
  Argument< GAMINR::Card1::Npend > npend; npend.value = 28;
  GIVEN( "invalid ngam1 input" ){
    WHEN( "invalid values for ngam1" ){
      for( auto ngam1 : {19, 100} ){
        iRecordStream<char> issNgam1(
            std::istringstream( std::to_string(ngam1) ) );
        REQUIRE_THROWS( argument::extract< GAMINR::Card1::Ngam1 >(
                          issNgam1, nendf, npend ) );
      }
      nendf.value *= -1;
      for( auto ngam1 : {-19, -100} ){
        iRecordStream<char> issNgam1(
            std::istringstream( std::to_string(ngam1) ) );
        REQUIRE_THROWS( argument::extract< GAMINR::Card1::Ngam1 >(
                          issNgam1, nendf, npend ) );
      }
    }
  } // GIVEN
  {
    iRecordStream<char> iss( std::istringstream(" cat") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam1 >( iss, nendf, npend ) );
  }{
    iRecordStream<char> iss( std::istringstream("    ") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam1 >( iss, nendf, npend ) );
  }{
    nendf.value *= -1;
    iRecordStream<char> iss( std::istringstream("  24") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam1 >( iss, nendf, npend ) );
  }{
    iRecordStream<char> iss( std::istringstream("  28") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam1 >( iss, nendf, npend ) );
  }{
    iRecordStream<char> iss( std::istringstream(" -29") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam1 >( iss, nendf, npend ) );
  }
}
