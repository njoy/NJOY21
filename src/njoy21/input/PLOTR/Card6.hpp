class Card6 {
public:
  #include "njoy21/input/PLOTR/Card6/Yl.hpp"
  #include "njoy21/input/PLOTR/Card6/Yh.hpp"
  #include "njoy21/input/PLOTR/Card6/Ystep.hpp"

  Argument< Yl > yl;
  Argument< Yh > yh;
  Argument< Ystep > ystep;

  template< typename Char >
  Card6 ( iRecordStream< Char >& is,
          Argument< PLOTR::Card4::Itype >& itype,
          Argument< PLOTR::Card4::Ytag >& ytag,
          const int ileg )
    try:
      yl( argument::extract< Yl >( is, itype.value ) ),
      yh( argument::extract< Yh >( is, this->yl.value ) ),
      ystep( argument::extract< Ystep >( is, this->yl.value, this->yh.value ) )
      {
        if( ileg != 0 and yh.value != std::nullopt ){
          ytag.value = ytag.value.value_or( *( this->yh.value ) );
        }
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card6" );
      throw e;
    }
};
