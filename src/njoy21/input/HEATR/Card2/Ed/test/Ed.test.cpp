#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "HEATR ed values",
  "[HEATR],[Card2], [Ed]"){
  GIVEN( "ed input and card2 matd input are provided" ){
    Argument< HEATR::Card2::Matd > matd; matd.value = 1325;
    WHEN( "ed input value is valid" ){
      std::vector<double> validValues{0.0, 1.0, 2.0};
      THEN( "the returned ed class has the correct value" ){
        for( auto ed : validValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( ed ) ) );
          REQUIRE( ed*dimwits::electronVolts == argument::extract< 
            HEATR::Card2::Ed >( iss, matd ).value );
        } 
      } // THEN
    } // WHEN
    WHEN( "ed input value is invalid" ){
      std::vector<double> invalidValues{-2.0, -1.0};
      THEN( "an exception is thrown" ){
        for( auto ed : invalidValues ){
          iRecordStream<char> iss( 
            std::istringstream( std::to_string( ed ) ) );
          REQUIRE_THROWS( argument::extract< 
            HEATR::Card2::Ed >( iss, matd ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
  GIVEN( "a card2 matd input value but no ed input value" ){
    Argument< HEATR::Card2::Matd > matd;   
    WHEN( "default value is in calculated table" ){
      std::vector<int> validMatd{ 419, 600, 1225, 1325, 1425, 2025, 2225, 
        2325, 2425, 2525, 2625, 2722, 2825, 2925, 4025, 4125, 4225, 4725,
        7325, 7425, 7925, 8225 };
      std::vector<int> validEd{    31,  31,   25,   27,   25,   40,   40,
          40,   40,   40,   40,   40,   40,   40,   40,   40,   60,   60, 
          90,   90,   30,   25 };
      THEN( "the default value is calculated and used" ){ 
        for( unsigned int i = 0; i < validMatd.size(); ++i ){
          iRecordStream<char> iss( std::istringstream( "/" ) );
          matd.value = validMatd[i];	
          REQUIRE( validEd[i]*dimwits::electronVolts == argument::extract<
            HEATR::Card2::Ed >( iss, matd ).value );
        }  
      } // THEN
    } // WHEN
    WHEN( "default value is not in calculated table" ){
      std::vector<int> validMatd{ 2125, 3025, 3925, 8235, 9228 };
      const int defaultValue = 25;
      THEN( "the default value is calculated and used" ){ 
        for( auto matdNum : validMatd ){
          iRecordStream<char> iss( std::istringstream( "/" ) );
          matd.value = matdNum;	
          REQUIRE( defaultValue * dimwits::electronVolts == argument::extract<
            HEATR::Card2::Ed >( iss, matd ).value );
        }  
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
