class Card3 {
public:
#include "njoy21/input/ACER/Card3/Hk.hpp"

  Argument< Hk > hk;

  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      hk( argument::extract< Hk >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3");
      throw e;
    }
};
