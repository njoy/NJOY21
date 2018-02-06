class Card6a {
public:
  #include "njoy21/input/PLOTR/Card6a/Ylabl.hpp"

  Argument< Ylabl > ylabl;

  template< typename Char >
  Card6a( iRecordStream< Char >& is )
    try:
      ylabl( argument::extract< Ylabl >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 6a - Label for the y-axis");
      throw e;
    }
};
