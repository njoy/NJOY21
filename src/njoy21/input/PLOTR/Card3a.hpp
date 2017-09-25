class Card3a {
public:
  #include "njoy21/input/PLOTR/Card3/Title.hpp"

  Argument< Title > title;

  template< typename Char >
  Card3a( iRecordStream< Char >& is )
    try:
      title( argument::extract< Title >( is ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3 - Title line 2");
      throw e;
    }
};
