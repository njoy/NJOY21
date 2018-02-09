class CISOTX {
public:

#include "njoy21/input/CCCCR/CISOTX/Card1.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card2.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card3.hpp"
#include "njoy21/input/CCCCR/CISOTX/Card4.hpp"

#include "njoy21/input/CCCCR/CISOTX/src/readCard2.hpp"
#include "njoy21/input/CCCCR/CISOTX/src/readCard3.hpp"
#include "njoy21/input/CCCCR/CISOTX/src/readCard4.hpp"

Card1 card1;
optional< Card2 > card2;
optional< Card3 > card3;
std::vector< Card4 > card4;

template< typename Istream >
CISOTX( Istream& is, const int ngroup, const int niso )
try:
  card1( is, ngroup ),
  card2( readCard2( is, ngroup, this->card1.ichix.value ) ),
  card3( readCard3( is, ngroup, this->card1.ichix.value ) ),
  card4( readCard4( is, niso ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading CISOTX." );
  throw e;
}
};
