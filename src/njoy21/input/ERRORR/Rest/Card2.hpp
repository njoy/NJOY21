class Card2 {
public:

using Matd = argument::common::Matd;
#include "njoy21/input/ERRORR/Rest/Card2/Ign.hpp"
#include "njoy21/input/ERRORR/Rest/Card2/Iwt.hpp"
#include "njoy21/input/ERRORR/Rest/Card2/Iprint.hpp"
#include "njoy21/input/ERRORR/Rest/Card2/Irelco.hpp"

Argument< Matd > matd;
Argument< Ign > ign;
Argument< Iwt > iwt;
Argument< Iprint > iprint;
Argument< Irelco > irelco;

template< typename Istream >
Card2( Istream& is )
try:
  matd( argument::extract< ERRORR::Rest::Card2::Matd >( is ) ),
  ign( argument::extract< ERRORR::Rest::Card2::Ign >( is ) ),
  iwt( argument::extract< ERRORR::Rest::Card2::Iwt >( is ) ),
  iprint( argument::extract< ERRORR::Rest::Card2::Iprint >( is ) ),
  irelco( argument::extract< ERRORR::Rest::Card2::Irelco >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card2." );
  throw e;
}
};
