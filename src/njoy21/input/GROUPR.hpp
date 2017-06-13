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

  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  Card5 card5;
  optional< std::tuple< Card6a, Card6b > > arbitraryNeutronStructureCards;
  optional< std::tuple< Card7a, Card7b > > arbitraryGammaStructureCards;
  optional< Card8a > card8a;
  optional< Card8b > card8b;
  optional< Card8c > card8c;
  optional< Card8d > card8d;
  optional< std::vector< Card9 > > card9List;
  optional< std::vector< Card10 > > card10List;

  template< typename Istream >
  GROUPR( Istream& is )
  try:
    card1( is ),
    card2( is ),
    card3( is ),
    card4( is, card2.ntemp ),
    card5( is, card2.nsigz )
  {
    if( card2.ign.value == 1 ){
      Card6a card6a( is );
      Card6b card6b( is, card6a.ngn );

      arbitraryNeutronStructureCards = std::make_tuple< Card6a, Card6b >(
          std::move( card6a ), std::move( card6b ) );
    }
    if( card2.igg.value == 1 ){
      Card7a card7a( is );
      Card7b card7b( is, card7a.ngg );

      arbitraryGammaStructureCards = std::make_tuple< Card7a, Card7b >(
          std::move( card7a ), std::move( card7b ) );
    }
    if( card2.iwt.value < 0 ){
      this->card8a = Card8a( is );
    }
    if( ( card2.iwt.value == 1 ) or ( card2.iwt.value == -1 ) ){
      this->card8b = Card8b( is );
    }
    if( ( card2.iwt.value == 4 ) or ( card2.iwt.value == -4 ) ){
      this->card8c = Card8c( is );
    }
    if( card2.iwt.value == 0 ){
      this->card8d = Card8d( is );
    }

    Card9 card9( is );
    if( card9.mfd.value ){
      this->card9List = std::vector< Card9 >();
      this->card9List->push_back( std::move( card9 ) );
      do {
        this->card9List->emplace_back( is );
      } while ( this->card9List->back().mfd.value );
    }

    Card10 card10( is );
    if( card10.matd.value ){
      this->card10List = std::vector< Card10 >();
      this->card10List->push_back( std::move( card10 ) );

      do {
        this->card10List->emplace_back( is );
      } while ( this->card10List->back().matd.value );
    }
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GROUPR input." );
    throw e;
  }
};
