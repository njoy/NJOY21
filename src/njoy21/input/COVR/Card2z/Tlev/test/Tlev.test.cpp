#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Tlev input values",
          "[Card2z], [Tlev]" ){
  const int nlev = 3;
  GIVEN( "a value for nlev (number of temperatures)" ){
    WHEN( "there are the correct number of tlev entries and they are valid" ){
      iRecordStream< char> iss( std::istringstream( "0.1 0.3 1.0" ) );
  
      THEN( "the tlev values can be extracted correctly" ){
        auto tlevs = argument::extract< COVR::Card2z::Tlev >( iss, nlev );
        std::vector< double > refTlevs = { 0.1, 0.3, 1.0 };
        REQUIRE( refTlevs == tlevs.value );
      }
    } // WHEN
  } // GIVEN
  
  GIVEN( "invalid inputs" ){
    WHEN( "the tlev values are invalid" ){
      for( std::string entry : {"0.0 0.5 1.0", "-0.1 0.3 1.0", "0.1 0.5 1.1"} ){
        iRecordStream<char> iss{ std::istringstream{ entry } };
  
        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< COVR::Card2z::Tlev >( iss, nlev ));
        }
      }
    } // WHEN
  
    WHEN( "the tlev values are not in increasing order" ){
      iRecordStream< char> iss( std::istringstream( "0.3 0.2 1.0" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
      }
    } // WHEN
  
    WHEN( "commas are used to separate values" ){
      iRecordStream< char> iss( std::istringstream("1.0, 2.0, 3.0") );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
      }
    } // WHEN
  
    WHEN( "there are not enough temperature values" ){
      iRecordStream< char> iss( std::istringstream("1.0 2.0") );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< COVR::Card2z::Tlev >( iss, nlev ) );
      }
    } // WHEN
  } // GIVEN
} // SCENARIO
