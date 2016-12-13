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
  long ln{0};
  GIVEN( "a value for nxtra (number of iz,aw pairs)" ){
    Argument< ACER::Card2::Nxtra > nxtra;
    nxtra.value = 3;

    WHEN( "there are the correct number of pairs and they are valid" ){
      std::istringstream issIzaw( 
          std::to_string( pairs[0].first ) + std::to_string( pairs[0].first ) +
          std::to_string( pairs[1].first ) + std::to_string( pairs[1].first ) +
          std::to_string( pairs[2].first ) + std::to_string( pairs[2].first ) );

      THEN( "the pairs can be extracted correctly" ){
        auto values = argument::extract< ACER::Card4::Izaw >(
                            issIzaw, ln, nxtra ).value;
        for( size_t i=0; i<values.size(); i++ ){
          REQUIRE( values[i].first == pairs[i].first );
          REQUIRE( values[i].second == pairs[i].second );
        }
      }
    }
  }
}

