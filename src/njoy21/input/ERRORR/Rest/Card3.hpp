class Card3 {
public:

#include "njoy21/input/ERRORR/Rest/Card3/Mprint.hpp"
#include "njoy21/input/ERRORR/Rest/Card3/Tempin.hpp"

Argument< Mprint > mprint;
Argument< Tempin > tempin;

template< typename Istream >
Card3( Istream& is )
try:
  mprint( argument::extract< ERRORR::Rest::Card3::Mprint >( is ) ),
  tempin( argument::extract< ERRORR::Rest::Card3::Tempin >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
