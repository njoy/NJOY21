class Rest {
public:

#include "njoy21/input/ERRORR/Rest/Card2.hpp"
#include "njoy21/input/ERRORR/Rest/Card3.hpp"
#include "njoy21/input/ERRORR/Rest/Card7.hpp"
#include "njoy21/input/ERRORR/Rest/Card8.hpp"
#include "njoy21/input/ERRORR/Rest/Card8a.hpp"
#include "njoy21/input/ERRORR/Rest/Card8b.hpp"
#include "njoy21/input/ERRORR/Rest/Card9.hpp"
#include "njoy21/input/ERRORR/Rest/Card10.hpp"
#include "njoy21/input/ERRORR/Rest/Card11.hpp"
#include "njoy21/input/ERRORR/Rest/Card12a.hpp"
#include "njoy21/input/ERRORR/Rest/Card12b.hpp"
#include "njoy21/input/ERRORR/Rest/Card13.hpp"
#include "njoy21/input/ERRORR/Rest/Card13b.hpp"

#include "njoy21/input/ERRORR/Rest/src/readIread1.hpp"
#include "njoy21/input/ERRORR/Rest/src/readCard10List.hpp"
#include "njoy21/input/ERRORR/Rest/src/readCard11.hpp"
#include "njoy21/input/ERRORR/Rest/src/readCard12a.hpp"
#include "njoy21/input/ERRORR/Rest/src/readCard13.hpp"
#include "njoy21/input/ERRORR/Rest/src/readCard13b.hpp"

Card2 card2;
Card3 card3;
Card7 card7;
optional< std::tuple< Card8, Card8a, optional< std::pair< Card8b,
                                            std::vector< Card9 > > > > > iread1;
optional< std::vector< Card10 > > card10List;
optional< Card11 > card11;
optional< Card12a > card12a;
Card12b card12b;
optional< Card13 > card13;
optional< Card13b > card13b;

template< typename Istream >
Rest( Istream& is, const int ngout, const int nstan )
try:
  card2( is ),
  card3( is ),
  card7( is, ngout ),
  iread1( readIread1( is, this->card7.iread.value ) ),
  card10( readCard10List( is, this->card7.iread.value ) ),
  card11( readCard11( is, nstan ) ),
  card12a( readCard12a( is, this->card2.ign.value ) ),
  card12b( is ),
  card13( readCard13( is, this->card2.iwt.value ) ),
  card13b( readCard13b( is, this->card2.iwt.value ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading Rest." );
  throw e;
}
};
