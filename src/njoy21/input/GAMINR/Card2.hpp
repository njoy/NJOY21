class Card2 {
public:
using Matb = argument::common::Matd;
using Igg = GROUPR::Card2::Igg;
#include "njoy21/input/GAMINR/Card2/Iwt.hpp"
#include "njoy21/input/GAMINR/Card2/Lord.hpp"
using Iprint = GROUPR::Card2::Iprint;

  Argument< Matb > matb;
  Argument< Igg > igg;
  Argument< Iwt > iwt;
  Argument< Lord > lord;
  Argument< Iprint > iprint;

  template< typename Char >
  Card2 ( iRecordStream< Char >& is )
    try:
      matb( argument::extract< Matb >( is ) ),
      igg( argument::extract< Igg >( is ) ),
      iwt( argument::extract< Iwt >( is ) ),
      lord( argument::extract< Lord >( is ) ),
      iprint( argument::extract< Iprint >( is ) )
      {
        Card::clear( is );
      }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card2" );
      throw e;
    }
};
