class Card4 {
public:

#include "njoy21/input/ERRORR/Endfv4/Card4/Nek.hpp"

Argument< Nek > nek;

template< typename Istream >
Card4( Istream& is )
try:
  nek( argument::extract< ERRORR::Endfv4::Card4::Nek >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card4." );
  throw e;
}
};
