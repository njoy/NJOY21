class Card5 {
public:
  #include "njoy21/input/DTFR/Card5/Jpos.hpp"
  #include "njoy21/input/DTFR/Card5/Mt.hpp"
  #include "njoy21/input/DTFR/Card5/Mult.hpp"

  Argument< Jpos > jpos;
  Argument< Mt    > mt;
  Argument< Mult > mult;

  template< typename Char >
  Card5( iRecordStream< Char >& is )
    try:
      jpos( argument::extract< Jpos >( is ) ),
      mt( argument::extract  < Mt   >( is ) ),
      mult( argument::extract< Mult >( is ) )
      { 
        Card::clear( is ); 
      }

    catch( std::exception& e ){
      Log::info("Trouble while validating Card5");
      throw e;
    }
};
