class Card2 {
public:
#include "njoy21/input/MODER/Card2/Tapeid.hpp"

  Argument< Tapeid > tapeid;
  
  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      tapeid( argument::extract< Tapeid >( is ) ){
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 2");
      throw e;
    }  
};
