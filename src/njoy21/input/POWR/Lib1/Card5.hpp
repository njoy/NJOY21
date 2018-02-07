class Card5{
public:

#include "njoy21/input/POWR/Lib1/Card5/Fsn.hpp"

Argument< Fsn > fsn;

template< typename Istream >
Card5( Istream& is )
try:
  fsn( argument::extract< POWR::Lib1::Card5::Fsn >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card5." );
  throw e;
}
};
