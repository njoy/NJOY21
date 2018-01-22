class Card12a{
public:

#include "njoy21/input/POWR/Lib3/Card12a/Nus.hpp"
#include "njoy21/input/POWR/Lib3/Card12a/Fis.hpp"
#include "njoy21/input/POWR/Lib3/Card12a/Xtr.hpp"

Argument< Nus > nus;
Argument< Fis > fis;
Argument< Xtr > xtr;

template< typename Istream >
Card12a( Istream& is )
try:
  nus( argument::extract< POWR::Lib3::Card12a::Nus >( is, 69 ) ),
  fis( argument::extract< POWR::Lib3::Card12a::Fis >( is, 69 ) ),
  xtr( argument::extract< POWR::Lib3::Card12a::Xtr >( is, 69 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reaidng Card 12a." );
  throw e;
}
};
