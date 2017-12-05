class Card2a {

  #include "njoy21/input/WIMSR/Card2a/Ngnd.hpp"
  #include "njoy21/input/WIMSR/Card2a/Nfg.hpp"
  #include "njoy21/input/WIMSR/Card2a/Nrg.hpp"
  #include "njoy21/input/WIMSR/Card2a/Igref.hpp"

  Ngnd ngnd;
  Nfg nfg;
  Nrg nrg;
  Igref igref;

  template< typename Istream >
  Card2a( Istream& is )
  try:
    ngnd( is ),
    nfg( is ),
    nrg( is ),
    igref( is, this->nfg.value, this->ngnd.value )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card2a." );
    throw e;
  }
};
