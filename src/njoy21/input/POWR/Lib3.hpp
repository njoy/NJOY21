class Lib3{
public:

#include "njoy21/input/POWR/Lib3/Card3.hpp"
#include "njoy21/input/POWR/Lib3/Card4.hpp"
#include "njoy21/input/POWR/Lib3/Card5.hpp"
#include "njoy21/input/POWR/Lib3/Card6.hpp"
#include "njoy21/input/POWR/Lib3/Card7.hpp"
#include "njoy21/input/POWR/Lib3/Card8.hpp"
#include "njoy21/input/POWR/Lib3/Card9.hpp"
#include "njoy21/input/POWR/Lib3/Card10.hpp"
#include "njoy21/input/POWR/Lib3/Card11.hpp"
#include "njoy21/input/POWR/Lib3/Card11a.hpp"
#include "njoy21/input/POWR/Lib3/Card12.hpp"
#include "njoy21/input/POWR/Lib3/Card12a.hpp"
#include "njoy21/input/POWR/Lib3/Card12b.hpp"
#include "njoy21/input/POWR/Lib3/Card12c.hpp"

#include "njoy21/input/POWR/Lib3/src/readCard4.hpp"
#include "njoy21/input/POWR/Lib3/src/readCard5.hpp"
#include "njoy21/input/POWR/Lib3/src/readCard678.hpp"
#include "njoy21/input/POWR/Lib3/src/readCard9.hpp"
#include "njoy21/input/POWR/Lib3/src/readCard10.hpp"
#include "njoy21/input/POWR/Lib3/src/readCard11.hpp"
#include "njoy21/input/POWR/Lib3/src/readCard12.hpp"

Card3 card3;
optional< Card4 > card4;
std::vector< Card5 > card5List;
optional< std::tuple< Card6, Card7, std::vector< Card8 > > > card678List;
optional< std::vector< Card9 > > card9List;
std::vector< optional< Card10 > > card10List;
std::vector< optional< std::pair< Card11, Card11a > > > card11List;
optional< std::vector< std::pair< Card12, optional< std::pair< Card12a,
  std::vector< std::pair< Card12b, optional< Card12c > > > > > > > > card12List;

template< typename Istream >
Lib3( Istream& is, const int iclaps )
try:
  card3( is ),
  card4( readCard4( is, this->card3.iopt.value ) ),
  card5List( readCard5( is, this->card3.mode.value,
                        this->card4->mat.value.size() ) ),
  card678List( readCard678( is, this->card3.if5.value ) ),
  card9List( readCard9( is, this->card3.if5.value,
                        this->card4->mat.value.size() ) ),
  card10List( readCard10( is, this->card5List, iclaps ) ),
  card11List( readCard11( is, this->card5List ) ),
  card12List( readCard12( is, this->card5List ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading values for lib=3." );
  throw e;
}
};
