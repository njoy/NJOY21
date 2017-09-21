class Card0 {
public:
  #include "njoy21/input/PLOTR/Card0/Nplt.hpp"
  #include "njoy21/input/PLOTR/Card0/Nplt0.hpp"

  Argument< Nplt > nplt;
  Argument< Nplt0 > nplt0;

  template< typename Char >
  Card0 ( iRecordStream< Char >& is )
    try:
      nplt( argument::extract< Nplt >( is ) ),
      nplt0( argument::extract< Nplt0 >( is, this->nplt ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating PLOTR Card0" );
      throw e;
    }
};
