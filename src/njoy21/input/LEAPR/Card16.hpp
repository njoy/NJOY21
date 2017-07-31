class Card16 {
public:
  #include "njoy21/input/LEAPR/Card16/Ow.hpp"

  Argument < Ow > ow;

  template< typename Char> 
  Card16( iRecordStream < Char >& iss, 
          Argument< LEAPR::Card14::Nd >& nd ,
          Argument< LEAPR::Card13::Twt >& twt,
          Argument< LEAPR::Card13::Tbeta >& tbeta )
    try:
     // ow( argument::extract < Ow > ( iss, nd ) ){
      ow( argument::extract < Ow > ( iss, nd, twt, tbeta ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card16" );
      throw e;
    }
};
