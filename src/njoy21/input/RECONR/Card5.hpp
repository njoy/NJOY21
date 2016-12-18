class Card5 {
public:
  #include "njoy21/input/RECONR/Card5/Cards.hpp"

  Argument< Cards > cards;

  template< typename Char >
  Card5( iRecordStream< Char >& is )
    try:
      cards( argument::extract< Cards >( is ) ){ Card::clear(is); }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 5");
      throw e;
    }
};
