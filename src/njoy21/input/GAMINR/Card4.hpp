class Card4 {
public:

  #include "njoy21/input/GAMINR/Card4/Ngg.hpp"
  #include "njoy21/input/GAMINR/Card4/Egg.hpp"

  Argument< Ngg > ngg;
  Argument< Egg > egg;

  template< typename Char >
  Card4( iRecordStream< Char >& is )
    try:
      ngg( argument::extract< Ngg >( is ) ),
      egg( argument::extract< Egg >( is, this->ngg.value+1 ) )
      { 
        Card::clear( is );
      }
    catch( std::exception& e ) {
      Log::info( "Trouble while validating GAMINR card 4" );
      throw e;
    }
};
