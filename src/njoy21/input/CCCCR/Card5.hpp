class Card5 {
public:

#include "njoy21/input/CCCCR/Card5/Hisnm.hpp"
#include "njoy21/input/CCCCR/Card5/Habsid.hpp"
#include "njoy21/input/CCCCR/Card5/Hident.hpp"
#include "njoy21/input/CCCCR/Card5/Hmat.hpp"
#include "njoy21/input/CCCCR/Card5/Imat.hpp"
#include "njoy21/input/CCCCR/Card5/Xspo.hpp"

Argument< Hisnm > hisnm;
Argument< Habsid > habsid;
Argument< Hident > hident;
Argument< Hmat > hmat;
Argument< Imat > imat;
Argument< Xspo > xspo;

template< typename Istream >
Card5( Istream& is )
try:
  hisnm( argument::extract< CCCCR::Card5::Hisnm >( is ) ),
  habsid( argument::extract< CCCCR::Card5::Habsid >( is ) ),
  hident( argument::extract< CCCCR::Card5::Hident >( is ) ),
  hmat( argument::extract< CCCCR::Card5::Hmat >( is ) ),
  imat( argument::extract< CCCCR::Card5::Imat >( is ) ),
  xspo( argument::extract< CCCCR::Card5::Xspo >( is ) )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card5." );
  throw e;
}
};
