class Card14 {
public:
  #include "njoy21/input/LEAPR/Card14/Nd.hpp"
  Argument < Nd > nd;

  template< typename Char> 
  Card14( iRecordStream < Char >& iss )
    try:
      nd( argument::extract < Nd > ( iss ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card14" );
      throw e;
    }
};
