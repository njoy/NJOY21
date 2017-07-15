class THERMR {
  public:
  #include "njoy21/input/THERMR/Card1.hpp"
  #include "njoy21/input/THERMR/Card2.hpp"
  #include "njoy21/input/THERMR/Card3.hpp"
  #include "njoy21/input/THERMR/Card4.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;

  template< typename Char >
    THERMR( iRecordStream<Char>& is )
      try: 
        card1( is ),
        card2( is, this->card1.nendf ),
        card3( is, this->card2.ntemp ),
        card4( is ){}
      catch( std::exception& e ){
        Log::info( "Trouble while validating THERMR input" );
        throw e;
      }
};
