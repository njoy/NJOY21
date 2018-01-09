class Card9{

#include "njoy21/input/POWR/Lib3/Card9/Aw.hpp"
#include "njoy21/input/POWR/Lib3/Card9/Indfis.hpp"
#include "njoy21/input/POWR/Lib3/Card9/Ntemp.hpp"

Aw aw;
Indfis indfis;
Ntemp ntemp;

template< typename Istream >
Card9( Istream& is )
try:
  aw( argument::extract< POWR::Lib3::Card9::Aw >( is ) ),
  indfis( argument::extract< POWR::Lib3::Card9::Indfis >( is ) ),
  Ntemp( argument::extract< POWR::Lib3::Card9::Ntemp >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 9." );
  throw e;
}
};
