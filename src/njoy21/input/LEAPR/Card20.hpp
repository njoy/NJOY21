class Card20 {
public:
#include "njoy21/input/LEAPR/Card20/Comment.hpp"

  Argument< Comment > comment;
  
  template< typename Char >
  Card20( iRecordStream< Char >& is )
    try:
      comment( argument::extract< Comment >( is ) )
      {
        Card::clear(is);
      }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card20");
      throw e;
    }

};
