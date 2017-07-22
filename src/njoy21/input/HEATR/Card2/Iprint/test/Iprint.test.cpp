#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR iprint values",
  "[HEATR], [Card2], [Iprint]"){
  GIVEN( "a card1 nplot input value of zero" ){
    Argument< HEATR::Card1::Nplot > nplot; nplot.value = 0;
    WHEN( "iprint input value is provided and is valid" ){
      std::vector<int> validValues{0, 1, 2};
      THEN( "the returned iprint class has the correct value" ){
        for( int iprint : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( iprint ) ) );
          REQUIRE( iprint == argument::extract< 
            HEATR::Card2::Iprint >( iss, nplot ).value );
        } 
      } // THEN
    } // WHEN
    WHEN( "no iprint input value is given" ){
      THEN( "the default value is used" ){ 
        iRecordStream<char> iss( std::istringstream( " /" ) );
        REQUIRE( 0 == argument::extract<
          HEATR::Card2::Iprint >( iss, nplot ).value );
      } // THEN
    } // WHEN
    WHEN( "iprint input values are invalid" ){
      std::vector<int> invalidValues{-2, -1, 3};
      THEN( "an exception is thrown" ){
        for( int iprint : invalidValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( iprint ) ) );
          REQUIRE_THROWS( argument::extract< 
            HEATR::Card2::Iprint >( iss, nplot ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "a nonzero card1 nplot input value" ){
    Argument< HEATR::Card1::Nplot > nplot; nplot.value = 20;
    WHEN( "iprint input value is valid" ){
      iRecordStream<char> iss( std::istringstream( "2" ) );
      THEN( "the returned iprint class has the correct value" ){
        REQUIRE( 2 == argument::extract<
          HEATR::Card2::Iprint >( iss, nplot ).value );
      } // THEN
    } // WHEN
    WHEN( "iprint input value is invalid" ){
      std::vector<int> invalidValues{-2, -1, 0, 1, 3};
      THEN( "an exception is thrown" ){
        for( int iprint : invalidValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( iprint ) ) );
          REQUIRE_THROWS( argument::extract< 
            HEATR::Card2::Iprint >( iss, nplot ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
