class Card2 {
public:

#include "njoy21/input/CCCCR/CISOTX/Card2/Spec.hpp"

Argument< Spec > spec;

template< typename Istream >
Card2( Istream& is, const int ngroup )
try:
  spec( argument::extract< CCCCR::CISOTX::Card2::Spec >( is, ngroup ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card2." );
  throw e;
}
};
