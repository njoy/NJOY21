class HEATR {
public:
  /* nested types */
  #include "njoy21/input/HEATR/Card1.hpp"
  #include "njoy21/input/HEATR/Card2.hpp"
  #include "njoy21/input/HEATR/Card3.hpp"
  #include "njoy21/input/HEATR/Card4.hpp"
  #include "njoy21/input/HEATR/Card5.hpp"
  #include "njoy21/input/HEATR/Card5a.hpp"

  using ControlTuple = std::tuple< Card4, Card5, optional< Card5a > >;

  Card1 card1;
  Card2 card2;
  optional<Card3> card3;

  template< typename Char >
  HEATR( iRecordStream<Char>& is )
    try:
      card1( is ),
      card2( is, card1.nplot ){
        if( card2.npk.value > 0 ){
          this->card3 = Card3( is, card2.npk );
	}
       // if( card2.nqa.value > 0 ){
          

      }
     catch( std::exception& e ){
       Log::info( "Trouble while validating HEATR input" );
       throw e;
     } 



};
