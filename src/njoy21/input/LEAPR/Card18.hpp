class Card18 {
public:
  #include "njoy21/input/LEAPR/Card18/Skappa.hpp"
  Argument < Skappa > skappa;

  template< typename Char> 
  Card18( iRecordStream < Char >& iss, Argument< LEAPR::Card17::Nka >& nka )
    try:
      skappa( argument::extract < Skappa > ( iss, nka ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card18" );
      throw e;
    }
};
