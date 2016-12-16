#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::vector< std::pair<int,double> > pairs{
  {1001, 0.99916733},
  {2003, 2.99012018},
  {92235, 233.02478975} };


SCENARIO( "Validating iz,aw input values",
         "[Card4], [Izaw]" ){
  GIVEN( "a value for nxtra (number of iz,aw pairs)" ){
    Argument< ACER::Card2::Nxtra > nxtra;
    nxtra.value = 3;

    WHEN( "there are the correct number of pairs and they are valid" ){
      iRecordStream<char> issIzaw( std::istringstream( 
        std::to_string( pairs[0].first ) + " " + std::to_string( pairs[0].second ) + " " +
        std::to_string( pairs[1].first ) + " " + std::to_string( pairs[1].second ) + " " +
        std::to_string( pairs[2].first ) + " " + std::to_string( pairs[2].second ) )
        );

      THEN( "the pairs can be extracted correctly" ){
        auto values = argument::extract< ACER::Card4::Izaw >(
                            issIzaw, nxtra ).value;
        for( size_t i=0; i<values.size(); i++ ){
          njoy::Log::info("i: {}", i);
          njoy::Log::info("values: {},{}", values[i].first, values[i].second);
          njoy::Log::info("pairs: {},{}", pairs[i].first, pairs[i].second);
          REQUIRE( values[i].first == pairs[i].first );
          REQUIRE( values[i].second == pairs[i].second );
        }
      }
    }
  }
}

