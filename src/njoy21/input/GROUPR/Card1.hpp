class Card1 {
public:
  #include "njoy21/input/GROUPR/Card1/Nendf.hpp"
  #include "njoy21/input/GROUPR/Card1/Npend.hpp"
  #include "njoy21/input/GROUPR/Card1/Ngout1.hpp"
  #include "njoy21/input/GROUPR/Card1/Ngout2.hpp"

  Argument< Nendf > nendf;
  Argument< Npend > npend;
  optional< std::tuple< Ngout1, Ngout2 > > ngout;

  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nendf( argument::extract< Nendf >( is ) ),
      npend( argument::extract< Npend >( is, this->nendf ) )
      {
        Ngout1 ngout1( is, this->nendf, this->npend );
        Ngout2 ngout2( is, this->nendf, this->npend, ngout1 );
        ngout = std::make_tuple< Ngout1, Ngout2 >(
            std::move(ngout1), std::move(ngout2) );

        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card1");
      throw e;
    }
};
