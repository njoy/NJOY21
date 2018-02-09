class Card12b {
public:

#include "njoy21/input/ERRORR/Rest/Card12b/Egn.hpp"

Argument< Egn > egn;

template< typename Istream >
Card12b( Istream& is, const int ngn )
try:
  egn( argument::extract< ERRORR::Rest::Card12b::Egn >( is, ngn+1 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card12b." );
  throw e;
}
};
