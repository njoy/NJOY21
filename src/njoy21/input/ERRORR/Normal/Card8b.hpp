class Card8b {
public:

#include "njoy21/input/ERRORR/Normal/Card8b/Ek.hpp"

Argument< Ek > ek;

template< typename Istream >
Card8b( Istream& is, const int nek )
try:
  ek( argument::extract< ERRORR::Normal::Card8b::Ek >( is, nek+1 ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card8b." );
  throw e;
}
};
