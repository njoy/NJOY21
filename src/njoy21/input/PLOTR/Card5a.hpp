class Card5a {
public:
  #include "njoy21/input/PLOTR/Card3/Title.hpp"

  Argument< Title > title;

  template< typename Char >
  Card5a( iRecordStream< Char >& is )
    try:
      title( argument::extract< Title >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 5a - Label for the x-axis");
      throw e;
    }
};
