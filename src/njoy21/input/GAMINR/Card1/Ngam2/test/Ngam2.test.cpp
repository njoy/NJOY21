#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "expected successes" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 24;
  Argument< GAMINR::Card1::Npend > npend; npend.value = 28;
  Argument< GAMINR::Card1::Ngam1 > ngam1; ngam1.value = 30;
  {
    iRecordStream<char> iss( std::istringstream("  20") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value  == 20 );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream(" -20") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value  == -20 );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream("  99") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value == 99 );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream(" -99") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value == -99 );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream("  59") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value == 59 );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream(" -59") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value == -59 );
  }{
    iRecordStream<char> iss( std::istringstream(" /") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream("   0") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value == 0 );
  }{
    iRecordStream<char> iss( std::istringstream(" -0") );
    REQUIRE( argument::extract
                  < GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ).value == 0 );
  }
}

SCENARIO( "expected failures" ){
  Argument< GAMINR::Card1::Nendf > nendf; nendf.value = 24;
  Argument< GAMINR::Card1::Npend > npend; npend.value = 28;
  Argument< GAMINR::Card1::Ngam1 > ngam1; ngam1.value = 30;
  {
    iRecordStream<char> iss( std::istringstream("  19") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream(" -19") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream("  100") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
    nendf.value *= -1;
    ngam1.value *= -1;
    iRecordStream<char> iss( std::istringstream(" -100") );
    REQUIRE_THROWS( argument::extract
                         <GAMINR::Card1::Ngam2 >( iss, nendf, npend, ngam1 ) );
  }{
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
