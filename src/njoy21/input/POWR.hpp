class POWR {

using Card1 = WIMSR::Card1;
#include "njoy21/input/POWR/Card2.hpp"

#include "njoy21/input/POWR/Lib1.hpp"
#include "njoy21/input/POWR/Lib2.hpp"
#include "njoy21/input/POWR/Lib3.hpp"

#include "njoy21/input/POWR/src/readLib1.hpp"
#include "njoy21/input/POWR/src/readLib2.hpp"
#include "njoy21/input/POWR/src/readLib3.hpp"

Card1 card1;
Card2 card2;
optional< std::vector< Lib1 > > lib1;
optional< std::vector< Lib2 > > lib2;
optional< Lib3 > lib3;

template< typename Istream >
POWR( Istream& is )
try:
  card1( is ),
  card2( is ),
  lib1( readLib1( is, this->card2.lib.value ) ),
  lib2( readLib2( is, this->card2.lib.value ) ),
  lib3( readLib3( is, this->card2.lib.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading in POWR module." );
  throw e;
}

};
