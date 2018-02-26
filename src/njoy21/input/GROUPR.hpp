class GROUPR {
public:
  /* nested types */
  #include "njoy21/input/GROUPR/Card1.hpp"
  #include "njoy21/input/GROUPR/Card2.hpp"
  #include "njoy21/input/GROUPR/Card3.hpp"
  #include "njoy21/input/GROUPR/Card4.hpp"
  #include "njoy21/input/GROUPR/Card5.hpp"
  #include "njoy21/input/GROUPR/Card6a.hpp"
  #include "njoy21/input/GROUPR/Card6b.hpp"
  #include "njoy21/input/GROUPR/Card7a.hpp"
  #include "njoy21/input/GROUPR/Card7b.hpp"
  #include "njoy21/input/GROUPR/Card8a.hpp"
  #include "njoy21/input/GROUPR/Card8b.hpp"
  #include "njoy21/input/GROUPR/Card8c.hpp"
  #include "njoy21/input/GROUPR/Card8d.hpp"
  #include "njoy21/input/GROUPR/Card9.hpp"
  #include "njoy21/input/GROUPR/Card10.hpp"

  using Card8Variant = std::variant< std::monostate, Card8b, Card8c, Card8d >;

  #include "njoy21/input/GROUPR/src/readArbitraryNeutronStructure.hpp"
  #include "njoy21/input/GROUPR/src/readArbitraryGammaStructure.hpp"
  #include "njoy21/input/GROUPR/src/readFluxCalculatorParameters.hpp"
  #include "njoy21/input/GROUPR/src/readFluxParameters.hpp"
  #include "njoy21/input/GROUPR/src/readCard9List.hpp"
  #include "njoy21/input/GROUPR/src/readCard10List.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  Card5 card5;
  optional< std::pair< Card6a, Card6b > > arbitraryNeutronStructureCards;
  optional< std::pair< Card7a, Card7b > > arbitraryGammaStructureCards;
  optional< Card8a > card8a;
  Card8Variant card8Variant;
  std::vector< Card9 > card9List;
  std::vector< Card10 > card10List;

  template< typename Istream >
  GROUPR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4( is, card2.ntemp ),
    card5( is, card2.nsigz ),
    arbitraryNeutronStructureCards( 
        readArbitraryNeutronStructure( is, card2.ign.value ) ),
    arbitraryGammaStructureCards( 
        readArbitraryGammaStructure( is, card2.igg.value ) ),
    card8a( readFluxCalculatorParameters( is, card2.iwt.value, card1 ) ),
    card8Variant( readFluxParameters( is, card2.iwt.value, card1 ) ),
    card9List( readCard9List( is, card2.ntemp.value ) ),
    card10List( readCard10List( is ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GROUPR input." );
    throw e;
  }
};
