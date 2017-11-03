class PLOTR {
public:
  /* nested types */
  #include "njoy21/input/PLOTR/Card0.hpp"
  #include "njoy21/input/PLOTR/Card1.hpp"
  #include "njoy21/input/PLOTR/Card2.hpp"
  #include "njoy21/input/PLOTR/Card3.hpp"
  #include "njoy21/input/PLOTR/Card3a.hpp"
  #include "njoy21/input/PLOTR/Card4.hpp"
  #include "njoy21/input/PLOTR/Card5.hpp"
  #include "njoy21/input/PLOTR/Card5a.hpp"
  #include "njoy21/input/PLOTR/Card6.hpp"
  #include "njoy21/input/PLOTR/Card6a.hpp"
  #include "njoy21/input/PLOTR/Card7.hpp"
  #include "njoy21/input/PLOTR/Card7a.hpp"
  #include "njoy21/input/PLOTR/Card8.hpp"
  #include "njoy21/input/PLOTR/Card9.hpp"
  #include "njoy21/input/PLOTR/Card10.hpp"
  #include "njoy21/input/PLOTR/Card10a.hpp"
  #include "njoy21/input/PLOTR/Card11.hpp"
  #include "njoy21/input/PLOTR/Card12.hpp"
  #include "njoy21/input/PLOTR/Card13.hpp"

  #include "njoy21/input/PLOTR/src/readCard7.hpp"
  #include "njoy21/input/PLOTR/src/Plot.hpp"
  #include "njoy21/input/PLOTR/src/readPlot.hpp"
  #include "njoy21/input/PLOTR/src/readCard10.hpp"
  #include "njoy21/input/PLOTR/src/readCard10a.hpp"
  #include "njoy21/input/PLOTR/src/readCard11.hpp"
  #include "njoy21/input/PLOTR/src/readCard13List.hpp"
  #include "njoy21/input/PLOTR/src/Freeform.hpp"
  #include "njoy21/input/PLOTR/src/readFreeform.hpp"
  #include "njoy21/input/PLOTR/src/Curves.hpp"
  #include "njoy21/input/PLOTR/src/readCurves.hpp"

  Card0 card0;
  Card1 card1;
  std::vector< std::pair< Card2, Curves > > curves;

  template< typename Istream >
  PLOTR( Istream& is )
  try:
    card0( is ),
    card1( is ),
    curves( readCurves( is, this->card1.lori ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating PLOTR input." );
    throw e;
  }
};
