class Card7a {
public:
  #include "njoy21/input/GROUPR/Card7a/Ngg.hpp"

  Argument< Ngg > ngg;

  template< typename Char >
  Card7a( iRecordStream< Char >& is )
    try:
      ngg( argument::extract< Ngg >( is ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card 7a");
      throw e;
    }
};
