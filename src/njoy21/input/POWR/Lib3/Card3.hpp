class Card3{
public:

#include "njoy21/input/POWR/Lib3/Card3/Nlib.hpp"
#include "njoy21/input/POWR/Lib3/Card3/Idat.hpp"
#include "njoy21/input/POWR/Lib3/Card3/Newmat.hpp"
#include "njoy21/input/POWR/Lib3/Card3/Iopt.hpp"
#include "njoy21/input/POWR/Lib3/Card3/Mode.hpp"
#include "njoy21/input/POWR/Lib3/Card3/If5.hpp"
#include "njoy21/input/POWR/Lib3/Card3/If4.hpp"

Argument< Nlib > nlib;
Argument< Idat > idat;
Argument< Newmat > newmat;
Argument< Iopt > iopt;
Argument< Mode > mode;
Argument< If5 > if5;
Argument< If4 > if4;

template< typename Istream >
Card3( Istream& is )
try:
  nlib( argument::extract< POWR::Lib3::Card3::Nlib >( is ) ),
  idat( argument::extract< POWR::Lib3::Card3::Idat >( is ) ),
  newmat( argument::extract< POWR::Lib3::Card3::Newmat >( is ) ),
  iopt( argument::extract< POWR::Lib3::Card3::Iopt >( is ) ),
  mode( argument::extract< POWR::Lib3::Card3::Mode >( is ) ),
  if5( argument::extract< POWR::Lib3::Card3::If5 >( is ) ),
  if4( argument::extract< POWR::Lib3::Card3::If4 >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 3." );
  throw e;
}
};
