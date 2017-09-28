class Card9 {
public:
  #include "njoy21/input/PLOTR/Card9/Icon.hpp"
  #include "njoy21/input/PLOTR/Card9/Isym.hpp"
  #include "njoy21/input/PLOTR/Card9/Idash.hpp"
  #include "njoy21/input/PLOTR/Card9/Iccol.hpp"
  #include "njoy21/input/PLOTR/Card9/Ithick.hpp"
  #include "njoy21/input/PLOTR/Card9/Ishade.hpp"

  Argument< Icon > icon;
  Argument< Isym > isym;
  Argument< Idash > idash;
  Argument< Iccol > iccol;
  Argument< Ithick > ithick;
  Argument< Ishade > ishade;

  template< typename Char >
  Card9 ( iRecordStream< Char >& is )
    try:
      icon( argument::extract< Icon >( is ) ),
      isym( argument::extract< Isym >( is ) ),
      idash( argument::extract< Idash >( is ) ),
      iccol( argument::extract< Iccol >( is ) ),
      ithick( argument::extract< Ithick >( is ) ),
      ishade( argument::extract< Ishade >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card9" );
      throw e;
    }
};
