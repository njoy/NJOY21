class Card11 {
public:
  #include "njoy21/input/PLOTR/Card11/Xv.hpp"
  #include "njoy21/input/PLOTR/Card11/Yv.hpp"
  #include "njoy21/input/PLOTR/Card11/Zv.hpp"
  #include "njoy21/input/PLOTR/Card11/X3.hpp"
  #include "njoy21/input/PLOTR/Card11/Y3.hpp"
  #include "njoy21/input/PLOTR/Card11/Z3.hpp"

  Argument< Xv > xv;
  Argument< Yv > yv;
  Argument< Zv > zv;
  Argument< X3 > x3;
  Argument< Y3 > y3;
  Argument< Z3 > z3;

  template< typename Char >
  Card11 ( iRecordStream< Char >& is )
    try:
      xv( argument::extract< Xv >( is ) ),
      yv( argument::extract< Yv >( is ) ),
      zv( argument::extract< Zv >( is ) ),
      x3( argument::extract< X3 >( is ) ),
      y3( argument::extract< Y3 >( is ) ),
      z3( argument::extract< Z3 >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card11" );
      throw e;
    }
};
