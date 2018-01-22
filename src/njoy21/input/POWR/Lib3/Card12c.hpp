class Card12c {
public:

#include "njoy21/input/POWR/Lib3/Card12c/Scat.hpp"

Argument< Scat > scat;

template< typename Istream >
Card12c( Istream& is, const int num )
try:
  scat( argument::extract< POWR::Lib3::Card12c::Scat >( is, num ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 12c." );
  throw e;
}
};
