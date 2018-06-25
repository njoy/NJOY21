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

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default values can be verified" ){
        auto tlev = argument::extract< COVR::Card2z::Tlev >( iss, 6 ).value;

        REQUIRE( tlev.size() == 6 );

        REQUIRE( Approx( 0.001 ) == tlev.at( 0 ) );
        REQUIRE( Approx( 0.1 ) == tlev.at( 1 ) );
        REQUIRE( Approx( 0.2 ) == tlev.at( 2 ) );
        REQUIRE( Approx( 0.3 ) == tlev.at( 3 ) );
        REQUIRE( Approx( 0.6 ) == tlev.at( 4 ) );
        REQUIRE( Approx( 1.0 ) == tlev.at( 5 ) );
      }
    } // WHEN
  } // GIVEN
  
  GIVEN( "invalid inputs" ){
    WHEN( "no value is provided, but the wrong nlev is given" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< COVR::Card2z::Tlev >( iss, 7 ) );
      }
    } // WHEN
    for( std::string entry : {"0.0 0.5 1.0", "-0.1 0.3 1.0", "0.1 0.5 1.1"} ){
      std::string situ( "invalid input " + entry + " is provided." );
      WHEN( situ.c_str() ){
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
