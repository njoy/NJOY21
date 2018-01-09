class Card3{

#include "njoy21/input/POWR/Lib2/Card3/Matd.hpp"
#include "njoy21/input/POWR/Lib2/Card3/Idtemp.hpp"
#include "njoy21/input/POWR/Lib2/Card3/Name.hpp"

Matd matd;
Idtemp idtemp;
Name name;

template< typename Istream >
Card3( Istream& is )
try:
  matd( argument::extract< POWR::Lib2::Card3::Matd >( is ) ),
  idtemp( argument::extract< POWR::Lib2::Card3::Idtemp >( is ) ),
  name( argument::extract< POWR::Lib2::Card3::Name >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 3." );
  throw e;
}
};
