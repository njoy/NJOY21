class CCCCR {
public:

#include "njoy21/input/CCCCR/Card1.hpp"
#include "njoy21/input/CCCCR/Card2.hpp"
#include "njoy21/input/CCCCR/Card3.hpp"
#include "njoy21/input/CCCCR/Card4.hpp"
#include "njoy21/input/CCCCR/Card5.hpp"

#include "njoy21/input/CCCCR/src/readCard5.hpp"

#include "njoy21/input/CCCCR/CISOTX.hpp"
#include "njoy21/input/CCCCR/CBRKXS.hpp"

#include "njoy21/input/CCCCR/src/readCISOTX.hpp"
#include "njoy21/input/CCCCR/src/readCBRKXS.hpp"

Card1 card1;
Card2 card2;
Card3 card3;
Card4 card4;
std::vector< Card5 > card5;
optional< CISOTX > cisotx;
optional< CBRKXS > cbrkxs;

template< typename Istream >
CCCCR( Istream& is )
try:
  card1( is ),
  card2( is ),
  card3( is ),
  card4( is ),
  card5( readCard5( is, this->card4.niso.value ) ),
  cisotx( readCISOTX( is, this->card1.nisot.value, this->card4.ngroup.value,
                      this->card4.niso.value ) ),
  cbrkxs( readCBRKXS( is, this->card1.nbrks.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading CCCCR module." );
  throw e;
}
};
