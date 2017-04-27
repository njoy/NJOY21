#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "GROUPR Card9 Mmtname", "[Card9], [Mmtname]"){
     GIVEN( "valid mtname values" ){
       std::vector< std::string > validValues{ "total", "elastic", "(n,2n)" };
       THEN( "the mtname value is correctly read and returned" ){
         for( auto& mtname : validValues ){
           iRecordStream<char> iss( std::istringstream( "'" + mtname + "'" ) );

           REQUIRE( mtname == 
                   argument::extract< GROUPR::Card9::Mtname >( iss ).value );
         }
       }
     }
     GIVEN( "invalid mtname values" ){
       THEN( "an exception is thrown" ){
         std::string value( "123456789 123456" );
         iRecordStream<char> iss( std::istringstream( "'" + value + "'" ) );
         REQUIRE_THROWS( argument::extract< GROUPR::Card9::Mtname >( iss ) );
       }
     }
} // SCENARIO
