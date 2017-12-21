class WIMSR {
public:
  /* nested types */
  #include "njoy21/input/WIMSR/Card1.hpp"
  #include "njoy21/input/WIMSR/Card2.hpp"
  #include "njoy21/input/WIMSR/Card2a.hpp"
  #include "njoy21/input/WIMSR/Card3.hpp"
  #include "njoy21/input/WIMSR/Card4.hpp"
  #include "njoy21/input/WIMSR/Card5.hpp"
  #include "njoy21/input/WIMSR/Card6a.hpp"
  #include "njoy21/input/WIMSR/Card6b.hpp"
  #include "njoy21/input/WIMSR/Card6c.hpp"
  #include "njoy21/input/WIMSR/Card7.hpp"
  #include "njoy21/input/WIMSR/Card8.hpp"

  #include "njoy21/input/WIMSR/src/readCard2a.hpp"
  #include "njoy21/input/WIMSR/src/readCard56.hpp"
  #include "njoy21/input/WIMSR/src/readCard8.hpp"

  Card1 card1;
  Card2 card2;
  optional< Card2a > card2a;
  Card3 card3;
  Card4 card4;
  optional< std::tuple< Card5, Card6a, Card6b, std::vector< Card6c > > >
    card56List;
  Card7 card7;
  optional< Card8 > card8;

  template< typename Istream >
  WIMSR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card2a( readCard2a( is, this->card2.igroup.value ) ),
    card3( is ),
    card4( is ),
    card56List( readCard56( is ) ),
    card7( is, this->card2.igroup.value, this->card2a->nrg.value ),
    card8( is, this->card2a->ngnd.value, this->card4.jp1.value )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading WIMSR input." );
    throw e;
  }
};
