class Normal {
public:

#include "njoy21/input/ERRORR/Normal/Card2.hpp"
#include "njoy21/input/ERRORR/Normal/Card3.hpp"
#include "njoy21/input/ERRORR/Normal/Card7.hpp"
#include "njoy21/input/ERRORR/Normal/Card8.hpp"
#include "njoy21/input/ERRORR/Normal/Card8a.hpp"
#include "njoy21/input/ERRORR/Normal/Card8b.hpp"
#include "njoy21/input/ERRORR/Normal/Card9.hpp"
#include "njoy21/input/ERRORR/Normal/Card10.hpp"
#include "njoy21/input/ERRORR/Normal/Card11.hpp"
#include "njoy21/input/ERRORR/Normal/Card12a.hpp"
#include "njoy21/input/ERRORR/Normal/Card12b.hpp"
#include "njoy21/input/ERRORR/Normal/Card13.hpp"
#include "njoy21/input/ERRORR/Normal/Card13b.hpp"

#include "njoy21/input/ERRORR/Normal/src/readIread1.hpp"
#include "njoy21/input/ERRORR/Normal/src/readCard10List.hpp"
#include "njoy21/input/ERRORR/Normal/src/readCard11.hpp"
#include "njoy21/input/ERRORR/Normal/src/readCard12ab.hpp"
#include "njoy21/input/ERRORR/Normal/src/readCard13.hpp"
#include "njoy21/input/ERRORR/Normal/src/readCard13b.hpp"

Card2 card2;
Card3 card3;
Card7 card7;
optional< std::tuple< Card8, Card8a, optional< std::pair< Card8b,
                                            std::vector< Card9 > > > > > iread1;
optional< std::vector< Card10 > > card10List;
optional< std::vector< Card11 > > card11List;
optional< std::pair< Card12a, Card12b > > card12ab;
optional< Card13 > card13;
optional< Card13b > card13b;

template< typename Istream >
Normal( Istream& is, const int ngout, const int nstan )
try:
  card2( is ),
  card3( is ),
  card7( is, ngout ),
  iread1( readIread1( is, this->card7.iread.value ) ),
  card10List( readCard10List( is, this->card7.iread.value ) ),
  card11List( readCard11( is, nstan ) ),
  card12ab( readCard12ab( is, this->card2.ign.value ) ),
  card13( readCard13( is, this->card2.iwt.value ) ),
  card13b( readCard13b( is, this->card2.iwt.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading Normal." );
  throw e;
}
};
