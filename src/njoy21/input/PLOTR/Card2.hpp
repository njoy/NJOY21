class Card2 {
public:
  #include "njoy21/input/PLOTR/Card2/Iplot.hpp"
  #include "njoy21/input/PLOTR/Card2/Iwcol.hpp"
  #include "njoy21/input/PLOTR/Card2/Factx.hpp"
  #include "njoy21/input/PLOTR/Card2/Facty.hpp"
  #include "njoy21/input/PLOTR/Card2/Ll.hpp"
  #include "njoy21/input/PLOTR/Card2/Ww.hpp"
  #include "njoy21/input/PLOTR/Card2/Wh.hpp"
  #include "njoy21/input/PLOTR/Card2/Wr.hpp"

  Argument< Iplot > iplot;
  Argument< Iwcol > iwcol;
  Argument< Factx > factx;
  Argument< Facty > facty;
  Argument< Ll > xll;
  Argument< Ll > yll;
  Argument< Ww > ww;
  Argument< Wh > wh;
  Argument< Wr > wr;

  template< typename Char >
  Card2 ( iRecordStream< Char >& is,
          Argument< PLOTR::Card1::Lori >& lori )
    try:
      iplot( argument::extract< Iplot >( is ) ),
      iwcol( argument::extract< Iwcol >( is ) ),
      factx( argument::extract< Factx >( is ) ),
      facty( argument::extract< Facty >( is ) ),
      // Second value of xll is the width of page left.
      xll( argument::extract< Ll >( is, (10.0 - (lori.value*2.5))) ),
      // Second value of yll is the height of page left.
      yll( argument::extract< Ll >( is, (7.5 + (lori.value*2.5))) ),
      ww( argument::extract< Ww >( is, lori.value ) ),
      wh( argument::extract< Wh >( is, lori.value ) ),
      wr( argument::extract< Wr >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card2" );
      throw e;
    }
};
