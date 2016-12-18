class Card2 {
public:
#include "njoy21/input/RECONR/Card2/Tlabel.hpp"

  Argument< Tlabel > tlabel;

  template< typename Char >
  Card2( std::iRecordStream< Char >& is )
    try:
      tlabel( argument::extract< Tlabel >( is ) ){
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 2");
      throw e;
    }
};
