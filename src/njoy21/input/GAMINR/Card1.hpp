class Card1 {
public:
using Nendf = GROUPR::Card1::Nendf;
using Npend = GROUPR::Card1::Npend;
#include "njoy21/input/GAMINR/Card1/Ngam1.hpp"
#include "njoy21/input/GAMINR/Card1/Ngam2.hpp"

  Argument< Nendf > nendf;
  Argument< Npend > npend;
  Argument< Ngam1 > ngam1;
  Argument< Ngam2 > ngam2;

  template< typename Char >
  Card1 ( iRecordStream< Char >& is )
    try:
      nendf( argument::extract< Nendf >( is ) ),
      npend( argument::extract< Npend >( is, this->nendf ) ),
      ngam1( argument::extract< Ngam1 >( is, this->nendf, this->npend ) ),
      ngam2( argument::extract< Ngam2 >( is, this->nendf, this->npend,
                                         this->ngam1 ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating GAMINR Card1" );
      throw e;
    }
};
