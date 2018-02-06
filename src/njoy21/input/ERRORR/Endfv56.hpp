class Endfv56 {
public:

#include "njoy21/input/ERRORR/Endfv56/Card7.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card8.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card8a.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card8b.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card9.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card10.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card11.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card12a.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card12b.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card13.hpp"
#include "njoy21/input/ERRORR/Endfv56/Card13b.hpp"

#include "njoy21/input/ERRORR/Endfv56/src/readIread1.hpp"
#include "njoy21/input/ERRORR/Endfv56/src/readCard10.hpp"
#include "njoy21/input/ERRORR/Endfv56/src/readCard11.hpp"
#include "njoy21/input/ERRORR/Endfv56/src/readCard12a.hpp"
#include "njoy21/input/ERRORR/Endfv56/src/readCard13.hpp"
#include "njoy21/input/ERRORR/Endfv56/src/readCard13b.hpp"

Card7 card7;
optional< std::tuple< Card8, Card8a, optional< std::pair< Card8b, Card9 > > > >
                                                                      iread1;
optional< Card10 > card10;
optional< Card11 > card11;
optional< Card12a > card12a;
Card12b card12b;
optional< Card13 > card13;
optional< Card13b > card13b;

template< typename Istream >
Endfv56( Istream& is, const int iverf, const int nstan, const int ign,
         const int iwt )
try:
  card7( is ),
  iread1( readIread1( is, this->card7.iread.value ) ),
  card10( readCard10( is, this->card7.iread.value ) ),
  card11( readCard11( is, nstan ) ),
  card12a( readCard12a( is, ign ) ),
  card12b( is ),
  card13( readCard13( is, iwt ) ),
  card13b( readCard13b( is, iwt ) )
{
}
catch( std::exception& e ){
  Log::info( "Trouble reading Endfv5/6 input." );
  throw e;
}
};
