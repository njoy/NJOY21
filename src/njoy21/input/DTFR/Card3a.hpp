class Card3a {
public:
#include "njoy21/input/DTFR/Card3a/Mti.hpp"
#include "njoy21/input/DTFR/Card3a/Mtc.hpp"
#include "njoy21/input/DTFR/Card3a/Nlc.hpp"

  Argument< Mti > mti;
  Argument< Mtc > mtc;
  Argument< Nlc > nlc;
  
  template< typename Char >
  Card3a( iRecordStream< Char >& is )
    try:
      mti ( argument::extract< Mti >( is ) ),
      mtc ( argument::extract< Mtc >( is ) ),
      nlc ( argument::extract< Nlc >( is ) )
      {
        Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 1");
      throw e;
    }
 
};
