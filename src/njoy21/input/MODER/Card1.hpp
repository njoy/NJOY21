class Card1 {
public:
#include "njoy21/input/MODER/Card1/Nin.hpp"
#include "njoy21/input/MODER/Card1/Nout.hpp"

  Argument< Nin > nin;
  Argument< Nout > nout;
  
  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nin( argument::extract< Nin >( is ) ),
      nout( argument::extract< Nout >( is, this->nin ) ){
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 1");
      throw e;
    }
  
};
