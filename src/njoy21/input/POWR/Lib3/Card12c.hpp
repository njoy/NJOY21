class Card12c {

#include "njoy21/input/POWR/Lib3/Card12c/Scat.hpp"

Scat scat;

template< typename Istream >
Card12c( Istream& is, const int num )
try:
  scat( argument::extract< POWR::Lib3::Card12c::Scat >( is, num ) )
{
  Card::clear( is );
}
catch( std::exception& ){
  Log::info( "Trouble reading Card 12c." );
  throw e;
}
};
