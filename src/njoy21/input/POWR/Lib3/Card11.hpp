class Card11{
public:

#include "njoy21/input/POWR/Lib3/Card11/Resnu.hpp"

Argument< Resnu > resnu;

template< typename Istream >
Card11( Istream& is )
try:
  resnu( argument::extract< POWR::Lib3::Card11::Resnu >( is, 69 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 11." );
  throw e;
}
};
