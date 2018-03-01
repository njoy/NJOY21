class Card8 {
public:

#include "njoy21/input/ERRORR/Normal/Card8/Nmt.hpp"
#include "njoy21/input/ERRORR/Normal/Card8/Nek.hpp"

Argument< Nmt > nmt;
Argument< Nek > nek;

template< typename Istream >
Card8( Istream& is )
try:
  nmt( argument::extract< ERRORR::Normal::Card8::Nmt >( is ) ),
  nek( argument::extract< ERRORR::Normal::Card8::Nek >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card8." );
  throw e;
}
};
