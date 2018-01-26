class Card11{
public:

#include "njoy21/input/POWR/Lib3/Card11/Resnu.hpp"

Argument< Resnu > resnu;

template< typename Istream >
Card11( Istream& is, const int nrg )
try:
  resnu( argument::extract< POWR::Lib3::Card11::Resnu >( is, nrg ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 11." );
  throw e;
}
};
