class Card3 {
public:
  #include "njoy21/input/PLOTR/Card3/Title.hpp"

  Argument< Title > title;

  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      title( argument::extract< Title >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3 - Title line 1");
      throw e;
    }
};
