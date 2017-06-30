class Card2 {
  public:
  #include "njoy21/input/DTFR/Card2/Iprint.hpp"
  #include "njoy21/input/DTFR/Card2/Ifilm.hpp"
  #include "njoy21/input/DTFR/Card2/Iedit.hpp"

  Argument< Iprint > iprint;
  Argument< Ifilm  > ifilm;
  Argument< Iedit  > iedit;

  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      iprint( argument::extract< Iprint >( is ) ),
      ifilm(  argument::extract< Ifilm  >( is ) ),
      iedit(  argument::extract< Iedit  >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble while validating Card2" );
      throw e;
    }


};
