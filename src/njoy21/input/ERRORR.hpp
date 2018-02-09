class ERRORR {
public:

#include "njoy21/input/ERRORR/Card1.hpp"

#include "njoy21/input/ERRORR/Dummy.hpp"
#include "njoy21/input/ERRORR/Rest.hpp"

#include "njoy21/input/ERRORR/src/readDummy.hpp"
#include "njoy21/input/ERRORR/src/readRest.hpp"

Card1 card1;
optional< Dummy > dummy;
optional< Rest > rest;

template< typename Istream >
ERRORR( Istream& is )
try:
  card1( is ),
  dummy( readDummy( is, this->card1.nendf.value ) ),
  rest( readRest( is, this->card1.nendf.value,
                      std::get<1>( *(this->card1.rest) ).value,
                      std::get<4>( *(this->card1.rest) ).value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading ERRORR." );
  throw e;
}
};
