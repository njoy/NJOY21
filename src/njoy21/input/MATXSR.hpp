class MATXSR {
public:
  /* nested types */
  #include "njoy21/input/MATXSR/Card1.hpp"
  #include "njoy21/input/MATXSR/Card2.hpp"
  #include "njoy21/input/MATXSR/Card3.hpp"
  #include "njoy21/input/MATXSR/Card4.hpp"
  #include "njoy21/input/MATXSR/Card5.hpp"
  #include "njoy21/input/MATXSR/Card6.hpp"
  #include "njoy21/input/MATXSR/Card7.hpp"
  #include "njoy21/input/MATXSR/Card8.hpp"
  #include "njoy21/input/MATXSR/Card9.hpp"
  #include "njoy21/input/MATXSR/Card10.hpp"

  #include "njoy21/input/MATXSR/src/readCard10List.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  Card5 card5;
  Card6 card6;
  Card7 card7;
  Card8 card8;
  Card9 card9;
  std::vector< Card10 > card10List;

  template< typename Istream >
  MATXSR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4( is ),
    card5( is ),
    card6( is ),
    card7( is ),
    card8( is ),
    card9( is ),
    card10List( readCard10List( is, this->card3.nmat.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating MATXSR input." );
    throw e;
  }
};
