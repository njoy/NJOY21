class Card12{

using Aw = POWR::Lib3::Card9::Aw;
#include "njoy21/input/POWR/Lib3/Card12/Temp.hpp"
#include "njoy21/input/POWR/Lib3/Card12/Fpa.hpp"

Aw aw;
Temp temp;
Fpa fpa;

template< typename Istream >
Card12( Istream& is )
try:
  aw( argument::extract< POWR::Lib3::Card12::Aw >( is ) ),
  temp( argument::extract< POWR::Lib3::Card12::Aw >( is ) ),
  fpa( argument::extract< POWR::Lib3::Card12::Fpa >( is, 69 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 12." );
  throw e;
}
}
