class GAMINR {
public:
  /* nested types */
  #include "njoy21/input/GAMINR/Card1.hpp"
  #include "njoy21/input/GAMINR/Card2.hpp"
  #include "njoy21/input/GAMINR/Card3.hpp"
  #include "njoy21/input/GAMINR/Card4.hpp"
  #include "njoy21/input/GAMINR/Card5.hpp"
  #include "njoy21/input/GAMINR/Card6.hpp"
  #include "njoy21/input/GAMINR/Card7.hpp"

  #include "njoy21/input/GAMINR/src/readArbitraryGammaStructure.hpp"
  #include "njoy21/input/GAMINR/src/readArbitraryWeights.hpp"
  #include "njoy21/input/GAMINR/src/readCard6List.hpp"
  #include "njoy21/input/GAMINR/src/readCard7List.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  optional< Card4 > arbitraryGammaStructureCard;
  optional< Card5 > arbitraryWeightsCard;
  std::vector< Card6 > card6List;
  std::vector< Card7 > card7List;

  template< typename Istream >
  GAMINR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    arbitraryGammaStructureCard(
        readArbitraryGammaStructure( is, card2.igg.value ) ),
    arbitraryWeightsCard( 
        readArbitraryWeights( is, card2.iwt.value ) ),
    card6List( readCard6List( is ) ),
    card7List( readCard7List( is ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GAMINR input." );
    throw e;
  }
};
