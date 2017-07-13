class Card3 {
public:
#include "njoy21/input/DTFR/Card3/Nlmax.hpp"
#include "njoy21/input/DTFR/Card3/Ng.hpp"
#include "njoy21/input/DTFR/Card3/Iptotl.hpp"
#include "njoy21/input/DTFR/Card3/Ipingp.hpp"
#include "njoy21/input/DTFR/Card3/Itabl.hpp"
#include "njoy21/input/DTFR/Card3/Ned.hpp"
#include "njoy21/input/DTFR/Card3/Ntherm.hpp"

  Argument< Nlmax > nlmax;
  Argument< Ng > ng;
  Argument< Iptotl > iptotl;
  Argument< Ipingp > ipingp;
  Argument< Itabl > itabl;
  Argument< Ned > ned;
  Argument< Ntherm > ntherm;
  
  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      nlmax ( argument::extract< Nlmax  >( is ) ),
      ng    ( argument::extract< Ng     >( is ) ),
      iptotl( argument::extract< Iptotl >( is ) ),
      ipingp( argument::extract< Ipingp >( is, this->iptotl ) ),
      itabl ( argument::extract< Itabl  >( is, this->iptotl, this->ng ) ),
      ned   ( argument::extract< Ned    >( is, this->iptotl ) ),
      ntherm( argument::extract< Ntherm >( is ) )
      {
        Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card3");
      throw e;
    }
 
};
