#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR npk values",
  "[HEATR],[Card2], [Npk]"){

  GIVEN( "valid npk inputs" ){
    std::vector<int> validValues{0, 1, 15};
    THEN( "the returned npk class has the correct value" ){
      for( int npk : validValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( npk ) ) );
        REQUIRE( npk == argument::extract< 
          HEATR::Card2::Npk >( iss ).value );
      } 
    } // THEN
  } // GIVEN

  GIVEN( "npk input values are invalid" ){
    std::vector<int> invalidValues{-2, -1};
    THEN( "an exception is thrown" ){
      for( int npk : invalidValues ){
        iRecordStream<char> iss( 
          std::istringstream( std::to_string( npk ) ) );
        REQUIRE_THROWS( argument::extract< 
          HEATR::Card2::Npk >( iss ) );
      }
    } // THEN
  } // GIVEN

  GIVEN( "no npk input value is given" ){
    THEN( "the default value is used" ){ 
      iRecordStream<char> iss( std::istringstream( " /" ) );
      REQUIRE( 0 == argument::extract<
        HEATR::Card2::Npk >( iss ).value );
    } // THEN
  } // GIVEN
} // SCENARIO
