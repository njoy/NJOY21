class UNRESR {
public:
  /* nested types */
  using Card1 = PURR::Card1;
  #include "njoy21/input/UNRESR/Card2.hpp"
  using Card3 = PURR::Card3;
  using Card4 = PURR::Card4;
  
  Card1 card1;
  using UNRESR_tuple = std::tuple< Card2, Card3, Card4 >;
  std::vector< UNRESR_tuple > cardSequence;

  template< typename Istream >
  UNRESR( Istream& is )
    try:
      card1( is ){
      
      Card2 card2(is );
      if( not card2.matd.value ){
        Log::error(
          "Must have at least one non-zero matd number in UNRESR Card2" );
        throw std::exception();
      }
      
      do{
        optional< Card3 > card3;
        try{
          card3 = Card3( is, card2.ntemp );
        } catch( std::exception& e ){
          Log::info( "Failed to read card 3" );
          throw e;
        }

        optional< Card4 > card4;
        try{
          card4 = Card4( is, card2.nsigz );
        } catch( std::exception& e ){
          Log::info( "Failed to read card 4" );
          throw e;
        }

        cardSequence.emplace_back(std::move(card2),
                                  std::move(*card3),
                                  std::move(*card4));
        try{
          card2 = Card2( is );
        } catch( std::exception& e ){
          Log::info( "Expected to read a terminating card 2 (matd=0).");
          throw e;
        }
      } while( card2.matd.value );

    } catch( std::exception& e ){
      Log::info( "Trouble validating UNRESR input" );
      throw e;
    }
};
