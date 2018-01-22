class Card6{
public:

#include "njoy21/input/POWR/Lib3/Card6/Ntis.hpp"
#include "njoy21/input/POWR/Lib3/Card6/Nfis.hpp"

Argument< Ntis > ntis;
Argument< Nfis > nfis;

template< typename Istream >
Card6( Istream& is )
try:
  ntis( argument::extract< POWR::Lib3::Card6::Ntis >( is ) ),
  nfis( argument::extract< POWR::Lib3::Card6::Nfis >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 6." );
  throw e;
}
};
