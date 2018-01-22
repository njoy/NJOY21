class Card10{
public:

#include "njoy21/input/POWR/Lib3/Card10/Lambda.hpp"

Argument< Lambda > lambda;

template< typename Istream >
Card10( Istream& is, const int nres )
try:
  lambda( argument::extract< POWR::Lib3::Card10::Lambda >( is, nres ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card 10." );
  throw e;
}
};
