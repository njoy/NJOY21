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
      yerr2( argument::extract< Yerr2 >( is, this->yerr1.value ) ),
      xerr1( argument::extract< Xerr1 >( is ) ),
      xerr2( argument::extract< Xerr2 >( is, this->xerr1.value ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card13" );
      throw e;
    }
};
