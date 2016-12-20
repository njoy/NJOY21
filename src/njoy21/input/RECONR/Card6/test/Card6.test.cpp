#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Verifying RECONR Card6 input", "[RECONR],[Card6]"){
  Argument< RECONR::Card3::Ngrid > ngrid; ngrid.value = 3;
  
  GIVEN( "valid enode" ){
    iRecordStream<char> iss( std::istringstream(" 1.0 2.0 3.0") );
    THEN( "the energy grid can be extracted" ){
      std::vector< dimwits::Quantity< dimwits::ElectronVolt > > refGrid{
          1.0*dimwits::electronVolt, 
          2.0*dimwits::electronVolt, 
          3.0*dimwits::electronVolt};
      RECONR::Card6 card6( iss, ngrid );
      REQUIRE( refGrid == card6.enode.value );
    }
  }
  GIVEN( "invalid enode" ){
    iRecordStream<char> iss( std::istringstream(" 1.0 2.0 3.0 4.0") );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( RECONR::Card6 card6( iss, ngrid ) );
    }
  }
}

