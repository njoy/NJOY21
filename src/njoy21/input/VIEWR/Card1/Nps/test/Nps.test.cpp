#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "nps output values",
         "[VIEWR],[Card1], [Nps]"){
  GIVEN( "valid nps tape values" ){
    std::vector<int> validValues{20, 42, 99};
    WHEN( "the infile value is valid" ){
      THEN( "the returned class has the correct tape value" ){
        for( int nps : validValues ){
          Argument< VIEWR::Card1::Infile > infile; 
          infile.value = 22;
          iRecordStream<char> issNps(
              std::istringstream( std::to_string(nps) ) );
          REQUIRE(nps == argument::extract< 
                           VIEWR::Card1::Nps >(issNps, infile).value );
        }
      }
    }
    WHEN( "the infile value is the same as the nps value" ){
      THEN( "an exception is thrown" ){
        Argument< VIEWR::Card1::Infile > infile;
        infile.value = 22;
        iRecordStream<char> issNps(
            std::istringstream( "22" ) );
        REQUIRE_THROWS(argument::extract< 
                       VIEWR::Card1::Nps >(issNps, infile));
      }
    }
  } // GIVEN

  GIVEN( "invalid nps tape values" ){
    Argument< VIEWR::Card1::Infile > infile;
    infile.value = 22;
    std::vector<int> invalidValues{-19, 19, -20, 0, 100, -100};
    for( auto nps : invalidValues ){
      iRecordStream<char> issNps(
          std::istringstream( std::to_string(nps) ) );
      REQUIRE_THROWS(argument::extract<VIEWR::Card1::Nps>(
              issNps, infile));
    }
  } // GIVEN
} // SCENARIO

