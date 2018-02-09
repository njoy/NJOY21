class Card3 {
public:

#include "njoy21/input/CCCCR/CISOTX/Card3/Spec.hpp"

Argument< Spec > spec;

template< typename Istream >
Card3( Istream& is, const int ngroup, const int ichix )
try:
  spec( argument::extract< CCCCR::CISOTX::Card3::Spec >( is, ngroup, ichix ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
