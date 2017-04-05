class Card1 {
public:
  #include "njoy21/input/GROUPR/Card1/Nendf.hpp"
  #include "njoy21/input/GROUPR/Card1/Npend.hpp"
  #include "njoy21/input/GROUPR/Card1/Ngout1.hpp"

  Argument< Nendf > nendf;
  Argument< Npend > npend;
  Argument< Ngout1 > ngout1;

  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nendf( argument::extract< Nendf >( is ) ),
      npend( argument::extract< Npend >( is, this->nendf ) ),
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card1");
      throw e;
    }
};
