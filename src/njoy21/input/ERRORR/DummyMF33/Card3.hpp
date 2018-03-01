class Card3 {
public:

#include "njoy21/input/ERRORR/DummyMF33/Card3/Mt.hpp"

Argument< Mt > mt;

template< typename Istream >
Card3( Istream& is )
try:
  mt( argument::extract< ERRORR::DummyMF33::Card3::Mt >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
