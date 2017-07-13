class ACER {
public:
  /* nested types */
  #include "njoy21/input/ACER/Card1.hpp"
  #include "njoy21/input/ACER/Card2.hpp"
  #include "njoy21/input/ACER/Card3.hpp"
  #include "njoy21/input/ACER/Card4.hpp"
  #include "njoy21/input/ACER/Card5.hpp"
  #include "njoy21/input/ACER/Card6.hpp"
  #include "njoy21/input/ACER/Card7.hpp"
  #include "njoy21/input/ACER/Card8.hpp"
  #include "njoy21/input/ACER/Card8a.hpp"
  #include "njoy21/input/ACER/Card9.hpp"
  #include "njoy21/input/ACER/Card10.hpp"
  #include "njoy21/input/ACER/Card11.hpp"

  Card1 card1;
  Card2 card2;
  Card3 card3;
  optional< Card4 > card4;
  optional< std::tuple< Card5, Card6, Card7 > > fastCards;
  optional< std::tuple< Card8, Card8a, Card9 > > thermalCards;
  optional< Card10 > card10;
  optional< Card11 > card11;

  template< typename Istream >
  ACER( Istream& is )
    try:
      card1( is ),
      card2( is ),
      card3( is ) {
      if( card2.nxtra.value != 0 ){
        this->card4 = Card4( is, card2.nxtra );
      }

      switch( card2.iopt.value ){
        case 1:
          {
            Card5 card5( is );
            Card6 card6( is, card1.ngend );
            Card7 card7( is );
            fastCards = std::make_tuple< Card5, Card6, Card7 >( 
                std::move( card5 ),
                std::move( card6 ),
                std::move( card7 ) );
          }
          break;
        case 2:
          {
            Card8 card8( is );
            Card8a card8a( is );
            Card9 card9( is );
            thermalCards = std::make_tuple< Card8, Card8a, Card9 >(
                std::move( card8 ),
                std::move( card8a ),
                std::move( card9 ) );
          }
          break;
        case 3:
          this->card10 = Card10( is );
          break;
        case 4:
        case 5:
          this->card11 = Card11( is );
          break;
        case 7:
          break;
        case 8:
          break;
      }
    } catch( std::exception& e ) {
      Log::info( "Troble validating ACER input." );
      throw e;
    }

};
