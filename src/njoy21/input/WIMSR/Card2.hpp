class Card2 {

  #include "njoy21/input/WIMSR/Card2/Iprint.hpp"
  #include "njoy21/input/WIMSR/Card2/Iverw.hpp"
  #include "njoy21/input/WIMSR/Card2/Igroup.hpp"

  Iprint iprint;
  Iverw iverw;
  Igroup igroup;

  template< typename Istream >
  Card2( Istream& is )
  try:
    iprint( is ),
    iverw( is ),
    igroup( is )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card2." );
    throw e;
  }
};
