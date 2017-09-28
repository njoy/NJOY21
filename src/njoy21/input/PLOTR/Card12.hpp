class Card12 {
public:
  #include "njoy21/input/PLOTR/Card12/Nform.hpp"

  Argument< Nform > nform;

  template< typename Char >
  Card12 ( iRecordStream< Char >& is )
    try:
      nform( argument::extract< Nform >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card12" );
      throw e;
    }
};
