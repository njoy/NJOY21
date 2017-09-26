class Card6 {
public:
  #include "njoy21/input/PLOTR/Card6/Yl.hpp"
  #include "njoy21/input/PLOTR/Card6/Yh.hpp"
  #include "njoy21/input/PLOTR/Card6/Ystep.hpp"

  Argument< Yl > yl;
  Argument< Yh > yh;
  Argument< Ystep > ystep;

  template< typename Char >
  Card6 ( iRecordStream< Char >& is )
    try:
      yl( argument::extract< Yl >( is ) ),
      yh( argument::extract< Yh >( is, this->yl ) ),
      ystep( argument::extract< Ystep >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card6" );
      throw e;
    }
};
