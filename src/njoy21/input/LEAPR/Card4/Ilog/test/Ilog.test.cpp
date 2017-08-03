#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR Card4 ilog values",
  "[LEAPR], [Card4], [Ilog]"){

  GIVEN( "valid ilog values" ){
    std::vector<int> validVal = {0, 1};
    THEN( "the returned calss has the correct value" ){
      for( auto& val : validVal ){
        iRecordStream<char> iss( std::istringstream( std::to_string( val ) ) );
        REQUIRE( val == argument::extract< LEAPR::Card4::Ilog >( iss ).value );
      } 
    } // THEN
  } // GIVEN

  GIVEN( "no ilog value" ){
    iRecordStream<char> iss( std::istringstream( " /" ) );
    THEN( "The default value is substituted in" ){
      REQUIRE( 0 == argument::extract< LEAPR::Card4::Ilog >( iss ).value );
    } // THEN 
  } // GIVEN

  GIVEN( "invalid ilog values" ){
    std::vector<int> validVal = {-1, 2};
    THEN( "an exception is thrown" ){
      for( auto& val : validVal ){
        iRecordStream<char> iss( std::istringstream( std::to_string( val ) ) );
        REQUIRE_THROWS( argument::extract< LEAPR::Card4::Ilog >( iss ).value );
      } 
    } // THEN
  } // GIVEN
} // SCENARIO
