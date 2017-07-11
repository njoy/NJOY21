class Card4 {
public:
#include "njoy21/input/DTFR/Card4/HollerithNames.hpp"

  Argument< HollerithNames > hollerithNames;
  
  template< typename Char >
  Card4( iRecordStream< Char >& is, Argument< DTFR::Card3::Iptotl >& iptotl )

    try:
      hollerithNames ( argument::extract< HollerithNames  >( is, iptotl.value - 3 ) )
      {
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info( "IPTOTL {}",iptotl.value );
      Log::info("Trouble while validating Card4");
      throw e;
    }
 
};
