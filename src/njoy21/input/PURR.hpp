class PURR {
public:
  /* nested types */
  #include "njoy21/input/PURR/Card1.hpp"
  #include "njoy21/input/PURR/Card2.hpp"
  #include "njoy21/input/PURR/Card3.hpp"
  #include "njoy21/input/PURR/Card4.hpp"

  Card1 card1;
  using PURR_tuple = std::tuple< Card2, Card3, Card4 >;
  std::vector< PURR_tuple > cardSequence;

  template< typename Istream >
  PURR( Istream& is, long& lineNumber )
    try:
      card1( is, lineNumber ){
      
      Card2 card2(is, lineNumber );
      if( not card2.matd.value ){
        Log::error(
          "Must have at least one non-zero matd number in PURR Card2" );
        throw std::exception();
      }
      
      do{
        optional< Card3 > card3;
        try{
          card3 = Card3( is, lineNumber, card2.ntemp );
        } catch( std::exception& e ){
          Log::info( "Failed to read card 3" );
          throw e;
        }

        optional< Card4 > card4;
        try{
          card4 = Card4( is, lineNumber, card2.nsigz );
        } catch( std::exception& e ){
          Log::info( "Failed to read card 4" );
          throw e;
        }

        cardSequence.emplace_back(std::move(card2),
                                  std::move(*card3),
                                  std::move(*card4));
        try{
          card2 = Card2( is, lineNumber );
        } catch( std::exception& e ){
          Log::info( "Expected to read a terminating card 2 (matd=0).");
          throw e;
        }
      } while( card2.matd.value );

    } catch( std::exception& e ){
      Log::info( "Trouble validating PURR input" );
      throw e;
    }
};
