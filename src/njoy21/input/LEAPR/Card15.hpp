class Card15 {
public:
  #include "njoy21/input/LEAPR/Card15/Oe.hpp"

  Argument < Oe > oe;

  template< typename Char> 
  Card15( iRecordStream < Char >& iss, Argument< LEAPR::Card14::Nd >& nd )
    try:
      oe( argument::extract < Oe > ( iss, nd ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card 12" );
      throw e;
    }
};
