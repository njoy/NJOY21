class Card8 {
public:
#include "njoy21/input/DTFR/Card8/Hisnam.hpp"
#include "njoy21/input/DTFR/Card8/Mat.hpp"
#include "njoy21/input/DTFR/Card8/Jsigz.hpp"
#include "njoy21/input/DTFR/Card8/Dtemp.hpp"

  Argument< Hisnam > hisnam;
  Argument< Mat    > mat;
  Argument< Jsigz  > jsigz;
  Argument< Dtemp  > dtemp;
  
  template< typename Char >
  Card8( iRecordStream< Char >& is )
    try:
      hisnam( argument::extract< Hisnam >( is ) ),
      mat   ( argument::extract< Mat >   ( is ) ),
      jsigz ( argument::extract< Jsigz > ( is ) ),
      dtemp ( argument::extract< Dtemp > ( is ) )
      {
	Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card8");
      throw e;
    }

};
