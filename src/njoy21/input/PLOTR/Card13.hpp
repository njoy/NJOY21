class Card13 {
public:
  #include "njoy21/input/PLOTR/Card13/Xdata.hpp"
  #include "njoy21/input/PLOTR/Card13/Ydata.hpp"
  #include "njoy21/input/PLOTR/Card13/Yerr1.hpp"
  #include "njoy21/input/PLOTR/Card13/Yerr2.hpp"
  #include "njoy21/input/PLOTR/Card13/Xerr1.hpp"
  #include "njoy21/input/PLOTR/Card13/Xerr2.hpp"

  Argument< Xdata > xdata;
  Argument< Ydata > ydata;
  Argument< Yerr1 > yerr1;
  Argument< Yerr2 > yerr2;
  Argument< Xerr1 > xerr1;
  Argument< Xerr2 > xerr2;

  template< typename Char >
  Card13 ( iRecordStream< Char >& is )
    try:
      xdata( argument::extract< Xdata >( is ) ),
      ydata( argument::extract< Ydata >( is ) ),
      yerr1( argument::extract< Yerr1 >( is ) ),
      yerr2( argument::extract< Yerr2 >( is ) ),
      xerr1( argument::extract< Xerr1 >( is ) ),
      xerr2( argument::extract< Xerr2 >( is ) )
      {
        if( this->yerr2.value != std::nullopt and 
            *( this->yerr2.value ) == 0.0 ) 
                                     this->yerr2.value = *( this->yerr1.value );
        if( this->xerr2.value != std::nullopt and 
            *( this->xerr2.value ) == 0.0 )
                                     this->xerr2.value = *( this->xerr1.value );
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card13" );
      throw e;
    }
};
