class ERRORR {
public:

#include "njoy21/input/ERRORR/Card1.hpp"
#include "njoy21/input/ERRORR/Card2.hpp"
#include "njoy21/input/ERRORR/Card3.hpp"

#include "njoy21/input/ERRORR/Endfv4.hpp"

#include "njoy21/input/ERRORR/Endfv56.hpp"

#include "njoy21/input/ERRORR/src/readEndfv4.hpp"
#include "njoy21/input/ERRORR/src/readEndfv56.hpp"

Card1 card1;
Card2 card2;
Card3 card3;
optional< Endfv4 > endfv4;
optional< Endfv56 > endfv56;

template< typename Istream >
ERRORR( Istream& is, const int iverf )
try:
  card1( is ),
  card2( is ),
  card3( is ),
  endfv4( readEndfv4( is, iverf ) ),
  endfv56( readEndfv56( is, iverf, this->card1.nstan.value,
                        this->card2.ign.value, this->card2.iwt.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading ERRORR." );
  throw e;
}
};
