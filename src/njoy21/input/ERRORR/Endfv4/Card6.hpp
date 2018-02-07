class Card6 {
public:

#include "njoy21/input/ERRORR/Endfv4/Card6/Akxy.hpp"

Argument< Akxy > akxy;

template< typename Istream >
Card6( Istream& is, const int nek )
try:
  akxy( is, nek, nmt, nmt )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card6." );
  throw e;
}
};
