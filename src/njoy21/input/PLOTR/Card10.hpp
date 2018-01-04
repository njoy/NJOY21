class Card10 {
public:
  #include "njoy21/input/PLOTR/Card10/Aleg.hpp"

  Argument< Aleg > aleg;

  template< typename Char >
  Card10( iRecordStream< Char >& is )
    try:
      aleg( argument::extract< Aleg >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 10");
      throw e;
    }
};
