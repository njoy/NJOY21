class Card3 {
public:

#include "njoy21/input/CCCCR/CBRKXS/Card3/Asig.hpp"

Argument< Asig > asig;

template< typename Istream >
Card3( Istream& is, const int nzi )
try:
  asig( argument::extract< CCCCR::CBRKXS::Card3::Asig >( is, nzi ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
