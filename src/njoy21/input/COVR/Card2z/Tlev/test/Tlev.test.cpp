#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tlev input values",
  "[Card2z], [Tlev]" ){
  GIVEN( "a value for nlev (number of temperatures)" ){
    Argument< COVR::Card2z::Nlev > nlev; nlev.value = 3;
    WHEN( "there are the correct number of tlev entries and they are valid" ){
      iRecordStream< char> iss( std::istringstream("0.1 0.3 1.0") );
      THEN( "the tlev values can be extracted correctly" ){
        auto tlevs = argument::extract< COVR::Card2z::Tlev >( iss, nlev );
        std::vector< double > refTlevs = { 0.1, 0.3, 1.0 };
        REQUIRE( refTlevs == tlevs.value );
      } // THEN
    } // WHEN
    WHEN( "the tlev values are invalid" ){
      std::vector< std::string > invalidValues = { 
        "0.0 0.5 1.0", "-0.1 0.3 1.0", "0.1 0.5 1.1" };
      THEN( "an exception is thrown" ){
        for( auto& entry : invalidValues ){
          iRecordStream<char> iss = { std::istringstream( entry ) };
          REQUIRE_THROWS(
            argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
        }
      } // THEN
    } // WHEN
    WHEN( "the tlev values are not in increasing order" ){
      iRecordStream< char> iss( std::istringstream("0.3 0.2 1.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
      } // THEN
    } // WHEN
    WHEN( "commas are used to separate values" ){
      iRecordStream< char> iss( std::istringstream("1.0, 2.0, 3.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
      } // THEN
    } // WHEN
    WHEN( "there are not enough temperature values" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS(
            argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
      } // THEN
    } // WHEN
    WHEN( "there are too many tlev values" ){
      iRecordStream< char> iss( std::istringstream("0.1 0.2 1.0 1.5") );
      THEN( "an exception is thrown" ){
        REQUIRE_NOTHROW(
            argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
