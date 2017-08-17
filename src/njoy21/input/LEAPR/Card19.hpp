class Card19 {
public:
  #include "njoy21/input/LEAPR/Card19/Cfrac.hpp"
  Argument < Cfrac > cfrac;

  template< typename Char> 
  Card19( iRecordStream < Char >& iss )
    try:
      cfrac( argument::extract < Cfrac > ( iss ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card19" );
      throw e;
    }
};
