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

ERRORR( Istream& is )
try:
  card1( is ),
  dummy( readDummy( is, this->card1.nendf.value ) ),
  rest( readRest( is, this->card1.nendf.value, this->card1.ngout.value,
                      this->card1.nstan.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading ERRORR." );
  throw e;
}
};
