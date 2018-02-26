#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "GAMINR Card6 Mmtname", "[Card6], [Mmtname]"){
  GIVEN( "valid mtname values" ){
    WHEN( "mfd=3" ){
      const int mfd = 3;
      std::vector< std::string > validValues{ "total", "elastic", "(n,2n)" };
      THEN( "the mtname value is correctly read and returned" ){
        for( auto& mtname : validValues ){
          iRecordStream<char> iss( std::istringstream( "'" + mtname + "'" ) );

          REQUIRE( mtname == 
                  argument::extract< GAMINR::Card6::Mtname >( iss, mfd ).value );
        }
      }
    }

    WHEN( "mfd =0" ){
      const int mfd = 0;

      THEN( "the mtname value is correctly empty" ){
        iRecordStream<char> iss( std::istringstream( " /" ) );
        REQUIRE( "" == argument::extract< GAMINR::Card6::Mtname >( iss, mfd ).value );
      }
    }
  }

  GIVEN( "invalid mtname values" ){
    const int mfd = 3;
    THEN( "an exception is thrown" ){
      iRecordStream<char> iss( std::istringstream( "'123456789 123456'" ) );
      REQUIRE_THROWS( argument::extract< GAMINR::Card6::Mtname >( iss, mfd ) );
    }
    THEN( "an exception is thrown" ){
      std::string value( "" );
      iRecordStream<char> iss( std::istringstream( "''" ) );
      REQUIRE_THROWS( argument::extract< GAMINR::Card6::Mtname >( iss, mfd ) );
    }
  }
} //SCENARIO
