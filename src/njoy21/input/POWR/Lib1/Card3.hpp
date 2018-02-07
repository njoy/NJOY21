class Card3{
public:

#include "njoy21/input/POWR/Lib1/Card3/Matd.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Rtemp.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Iff.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Nsgz.hpp"
#include "njoy21/input/POWR/Lib1/Card3/Izref.hpp"

#include "njoy21/input/POWR/Lib1/Card3/src/readRest.hpp"

Argument< Matd > matd;
optional< std::tuple< Argument< Rtemp >, Argument< Iff >, Argument< Nsgz >,
                      Argument< Izref > > > rest;

template< typename Istream >
Card3( Istream& is )
try:
  matd( argument::extract< POWR::Lib1::Card3::Matd >( is ) ),
  rest( readRest( is, this->matd.value ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}

};
