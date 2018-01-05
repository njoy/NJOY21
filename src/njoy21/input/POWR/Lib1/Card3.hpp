class Card3{

#include "njoy21/input/POWR/Lib1/Card3/Matd.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Rtemp.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Iff.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Nsgz.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Izref.hpp"

#include "njoy21/input/POWR/Lib1/Card3/src/readRtemp.hpp"
#include "njoy21/input/POWR/Lib1/Card3/src/readIff.hpp"
#include "njoy21/input/POWR/Lib1/Card3/src/readNsgz.hpp"
#include "njoy21/input/POWR/Lib1/Card3/src/readIzref.hpp"

Matd matd;
optional< Rtemp > rtemp;
optional< Iff > iff;
optional< Nsgz > nsgz;
optional< Izref > izref;

template< typename Istream >
Card3( Istream& is )
try:
  matd( is ),
  rtemp( readRtemp( is, this->matd.value ) ),
  iff( readIff( is, this->matd.value ) ),
  nsgz( readNsgz( is, this->matd.value ) ),
  izref( readIzref( is, this->matd.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}

};
