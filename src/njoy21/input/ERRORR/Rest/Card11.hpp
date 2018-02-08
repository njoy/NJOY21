class Card11 {
public:

#include "njoy21/input/ERRORR/Rest/Card11/Matb.hpp"
#include "njoy21/input/ERRORR/Rest/Card11/Mtb.hpp"
#include "njoy21/input/ERRORR/Rest/Card11/Matc.hpp"
#include "njoy21/input/ERRORR/Rest/Card11/Mtc.hpp"

#include "njoy21/input/ERRORR/Rest/Card11/src/readRest.hpp"

Argument< Matb > matb;
optional< std::tuple< Argument< Mtb >, Argument< Matc >, Argument< Mtc > > rest;

template< typename Istream >
Card11( Istream& is )
try:
  matb( argument::extract< ERRORR::Rest::Card11::Matb >( is ) ),
  rest( readRest( is, this->matb.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card11." );
  throw e;
}
};
