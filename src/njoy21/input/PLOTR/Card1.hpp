class Card1 {
public:
  #include "njoy21/input/PLOTR/Card1/Lori.hpp"
  #include "njoy21/input/PLOTR/Card1/Istyle.hpp"
  #include "njoy21/input/PLOTR/Card1/Size.hpp"
  #include "njoy21/input/PLOTR/Card1/Ipcol.hpp"

  Argument< Lori > lori;
  Argument< Istyle > istyle;
  Argument< Size > size;
  Argument< Ipcol > ipcol;

  template< typename Char >
  Card1 ( iRecordStream< Char >& is )
    try:
      lori( argument::extract< Lori >( is ) ),
      istyle( argument::extract< Istyle >( is ) ),
      size( argument::extract< Size >( is ) ),
      ipcol( argument::extract< Ipcol >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card1" );
      throw e;
    }
};
