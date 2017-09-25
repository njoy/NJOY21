class Card6a {
public:
  #include "njoy21/input/PLOTR/Card3/Title.hpp"

  Argument< Title > title;

  template< typename Char >
  Card6a( iRecordStream< Char >& is )
    try:
      title( argument::extract< Title >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 6a - Label for the y-axis");
      throw e;
    }
};
