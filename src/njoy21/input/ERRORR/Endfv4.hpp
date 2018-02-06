class Endfv4 {
public:

#include "njoy21/input/ERRORR/Endfv4/Card4.hpp"
#include "njoy21/input/ERRORR/Endfv4/Card5.hpp"
#include "njoy21/input/ERRORR/Endfv4/Card6.hpp"

#include "njoy21/input/ERRORR/Endfv4/src/readCard56.hpp"

Card4 card4;
optional< std::pair< Card5, Card6 > > card56;

template< typename Istream >
Endfv4( Istream& is )
try:
  card4( is ),
  card56( readCard56( is, this->card4.nek.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading Endfv4 input." );
  throw e;
}
};
