#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR mta values",
  "[HEATR],[Card4], [Mta]"){
  GIVEN( "a card2 nqa input value" ){
    Argument< HEATR::Card2::Nqa > nqa; nqa.value = 4;
    WHEN( "mta entries are valid" ){
      iRecordStream<char> iss( std::istringstream( "46 47 48 49" ) );
      THEN( "the mt values can be extracted correctly" ){
        auto mts = argument::extract< HEATR::Card4::Mta >( iss, nqa );
        std::vector<int> refMts{ 46, 47, 48, 49 };
	REQUIRE( refMts == mts.value );
      } // THEN
    } // WHEN
    WHEN( "mta entries are out of range" ){
      iRecordStream<char> iss1( std::istringstream( "0 3 500 999" ) );
      iRecordStream<char> iss2( std::istringstream( "1 -1 500 999" ) );
      iRecordStream<char> iss3( std::istringstream( "1 3 500 1000" ) );
      THEN( "an exception is thrown" ){ 
        REQUIRE_THROWS( argument::extract< HEATR::Card4::Mta >( iss1, nqa ) );
        REQUIRE_THROWS( argument::extract< HEATR::Card4::Mta >( iss2, nqa ) );
        REQUIRE_THROWS( argument::extract< HEATR::Card4::Mta >( iss3, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "commas are used to separate values" ){
      iRecordStream<char>iss( std::istringstream( "302, 303, 400, 449" ) );
      THEN( "an exception is thrown" ){ 
        REQUIRE_THROWS( argument::extract< HEATR::Card4::Mta >( iss, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "there are not enough mt values" ){
      iRecordStream<char> iss( std::istringstream( "302 449 450" ) );
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< HEATR::Card4::Mta >( iss, nqa ) );
      } // THEN
    } // WHEN
    WHEN( "there are too many mt values" ){
      iRecordStream<char> iss( std::istringstream( "1 302 449 450 999 " ) );
      THEN( "an exception is not thrown" ){
        REQUIRE_NOTHROW( argument::extract< HEATR::Card4::Mta >( iss, nqa ) );
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
