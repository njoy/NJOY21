class Card4 {
public:
  #include "njoy21/input/RECONR/Card4/Err.hpp"
  #include "njoy21/input/RECONR/Card4/Tempr.hpp"
  #include "njoy21/input/RECONR/Card4/Errmax.hpp"
  #include "njoy21/input/RECONR/Card4/Errint.hpp"

  Argument< Err > err;
  Argument< Tempr > tempr;
  Argument< Errmax > errmax;
  Argument< Errint > errint;

  template< typename Char >
  Card4( std::iRecordStream< Char >& is )
    try:
      err( argument::extract< Err >( is ) ),
      tempr( argument::extract< Tempr >( is ) ),
      errmax( argument::extract< Errmax >( is, err ) ),
      errint( argument::extract< Errint >( is, err ) ){ Card::clear(is); }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card4" );
      throw e;
    }
};
