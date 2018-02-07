class Card5 {
public:

#include "njoy21/input/ERRORR/Endfv4/Card5/Ek.hpp"

Argument< Ek > ek;

template< typename Istream >
Card5( Istream& is, const int nek )
try:
  ek( argument::extract< ERRORR::Endfv4::Card5::Ek >( is, nek+1 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card5." );
  throw e;
}
};
