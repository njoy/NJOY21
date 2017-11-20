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

  #include "njoy21/input/MATXSR/src/readCard4List.hpp"
  #include "njoy21/input/MATXSR/src/readCard56List.hpp"
  #include "njoy21/input/MATXSR/src/readCard789List.hpp"
  #include "njoy21/input/MATXSR/src/readCard10List.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  std::vector< Card4 > card4List;
  std::vector< std::pair< Card5, Card6 > > card56List;
  std::vector< std::tuple< Card7, Card8, Card9 > > card789List;
  std::vector< Card10 > card10List;

  template< typename Istream >
  MATXSR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4List( readCard4List( is, this->card3.nholl.value ) ),
    card56List( readCard56List( is, this->card3.npart.value ) ),
    card789List( readCard789List( is, this->card3.ntype.value ) ),
    card10List( readCard10List( is, this->card3.nmat.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating MATXSR input." );
    throw e;
  }
};
