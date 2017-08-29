class Card4 {
public:

  using Ngg = GROUPR::Card7a::Ngg;
  #include "njoy21/input/GAMINR/Card4/Egg.hpp"

  Argument< Ngg > ngg;
  Argument< Egg > egg;

  template< typename Char >
  Card4( iRecordStream< Char >& is )
    try:
      ngg( argument::extract< Ngg >( is ) ),
      egg( argument::extract< Egg >( is, this->ngg ) )
      { 
        Card::clear( is );
      }
    catch( std::exception& e ) {
      Log::info( "Trouble while validating card 4" );
      throw e;
    }
};
