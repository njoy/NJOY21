class Card7 {
public:
#include "njoy21/input/DTFR/Card7/Nptabl.hpp"
#include "njoy21/input/DTFR/Card7/Ngp.hpp"

  Argument< Nptabl > nptabl;
  Argument< Ngp    > ngp;
  
  template< typename Char >
  Card7( iRecordStream< Char >& is )
    try:
      nptabl( argument::extract< Nptabl >( is ) ),
      ngp   ( argument::extract< Ngp    >( is ) )
      {
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card7");
      throw e;
    }
  
};
