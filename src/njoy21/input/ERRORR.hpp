class ERRORR {
public:

#include "njoy21/input/ERRORR/Card1.hpp"

#include "njoy21/input/ERRORR/DummyMF33.hpp"
#include "njoy21/input/ERRORR/Normal.hpp"

#include "njoy21/input/ERRORR/src/readDummyMF33.hpp"
#include "njoy21/input/ERRORR/src/readNormal.hpp"

Card1 card1;
optional< DummyMF33 > dummyMF33;
optional< Normal > normal;

template< typename Istream >
ERRORR( Istream& is )
try:
  card1( is ),
  dummyMF33( readDummyMF33( is, this->card1.nendf.value ) ),
  normal( readNormal( is, this->card1.nendf.value,
                      std::get<1>( *(this->card1.rest) ).value,
                      std::get<4>( *(this->card1.rest) ).value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading ERRORR." );
  throw e;
}
};
