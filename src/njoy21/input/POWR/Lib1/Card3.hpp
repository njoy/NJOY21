class Card3{
public:

#include "njoy21/input/POWR/Lib1/Card3/Matd.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Rtemp.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Iff.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Nsgz.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Izref.hpp"

#include "njoy21/input/POWR/Lib1/Card3/src/readRtemp.hpp"
#include "njoy21/input/POWR/Lib1/Card3/src/readIff.hpp"
#include "njoy21/input/POWR/Lib1/Card3/src/readNsgz.hpp"

Argument< Matd > matd;
optional< Argument< Rtemp > > rtemp;
optional< Argument< Iff > > iff;
optional< Argument< Nsgz > > nsgz;
Argument< Izref > izref;

template< typename Istream >
Card3( Istream& is )
try:
  matd( argument::extract< POWR::Lib1::Card3::Matd >( is ) ),
  rtemp( readRtemp( is, this->matd.value ) ),
  iff( readIff( is, this->matd.value ) ),
  nsgz( readNsgz( is, this->matd.value ) ),
  izref( argument::extract< POWR::Lib1::Card3::Izref >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}

};
