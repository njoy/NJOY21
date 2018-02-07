class Card12a{
public:

#include "njoy21/input/POWR/Lib3/Card12a/Nus.hpp"
#include "njoy21/input/POWR/Lib3/Card12a/Fis.hpp"
#include "njoy21/input/POWR/Lib3/Card12a/Xtr.hpp"

Argument< Nus > nus;
Argument< Fis > fis;
Argument< Xtr > xtr;

template< typename Istream >
Card12a( Istream& is, const size_t ngnd )
try:
  nus( argument::extract< POWR::Lib3::Card12a::Nus >( is, ngnd ) ),
  fis( argument::extract< POWR::Lib3::Card12a::Fis >( is, ngnd ) ),
  xtr( argument::extract< POWR::Lib3::Card12a::Xtr >( is, ngnd ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reaidng Card 12a." );
  throw e;
}
};
