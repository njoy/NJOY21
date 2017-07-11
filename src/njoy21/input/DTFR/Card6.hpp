class Card6 {
public:
#include "njoy21/input/DTFR/Card6/Nlmax.hpp"
#include "njoy21/input/DTFR/Card6/Ng.hpp"

  Argument< Nlmax > nlmax;
  Argument< Ng > ng;
  
  template< typename Char >
  Card6( iRecordStream< Char >& is )
    try:
      nlmax( argument::extract< Nlmax >( is ) ),
      ng   ( argument::extract< Ng >   ( is ) )
      {
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card6");
      throw e;
    }
  
};
