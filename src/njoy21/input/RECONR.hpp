class RECONR {
public:
  /* nested types */
  #include "njoy21/input/RECONR/Card1.hpp"
  #include "njoy21/input/RECONR/Card2.hpp"
  #include "njoy21/input/RECONR/Card3.hpp"
  #include "njoy21/input/RECONR/Card4.hpp"
  #include "njoy21/input/RECONR/Card5.hpp"
  #include "njoy21/input/RECONR/Card6.hpp"

  Card1 card1;
  Card2 card2;
  using RECONR_tuple = std::tuple< 
                        Card3, Card4, 
                        optional< std::vector< Card5 > >, 
                        optional< Card6 > 
                       >;
  std::vector< RECONR_tuple > cardSequence;

  template< typename Istream >
  RECONR( Istream& is, long& lineNumber )
    try:
      card1( is, lineNumber ),
      card2( is, lineNumber ) {

      // Read Card3
      Card3 card3(is, lineNumber );
      if ( not card3.mat.value ){
        Log::error( 
          "Must have at least one non-zero mat number in RECONR Card3" );
        throw std::exception();
      }
      do{
        optional< Card4 > card4;
        try {
          card4 = Card4(is, lineNumber);
        } catch( std::exception& e ){
          Log::info( "Failed to read card 4" );
          throw e;
        }

        optional< std::vector< Card5 > > card5;
        try {
          if( card3.ncards.value ){
            card5 = std::vector< Card5 >();
            for( int n=0; n < card3.ncards.value; n++ ){
              card5->emplace_back(is, lineNumber);
            }
          }
        } catch( std::exception& e){
          Log::info("Trouble reading card 5 cards.");
          Log::info( "Expecting {} cards, read {} card(s) instead.",
                    card3.ncards.value, (card5->size()) );
          throw e;
        }

        optional< Card6 > card6;
        if( card3.ngrid.value ){
          try {
            card6 = Card6(is, lineNumber, card3.ngrid);
          } catch( std::exception& e ){
            Log::info( "Failed reading card 6." );
            Log::info( "Expected to read {} grid points on card 6.", 
                       card3.ngrid.value );
            throw e;
          }
        } else {
        }

        cardSequence.emplace_back(std::move(card3), 
                                  std::move(*card4), 
                                  std::move(card5), 
                                  std::move(card6));

        try{
          card3 = Card3( is, lineNumber );
        } catch( std::exception& e ){
          Log::info( "Expected to read a terminating card 3 (mat=0).");
          Log::info( "Read {} card 5 entries, expected {}", 
                    (card5 ? card5->size() : 0), card3.ncards.value );
          Log::info( "Read {} grid points from card 6, expected to read {}",
                     (card6 ? card6->enode.value.size() : 0), 
                     card3.ngrid.value  );
          throw e;
        }
      } while( card3.mat.value );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating RECONR input" );
      throw e;
    }
};

