class Card17 {
public:
  #include "njoy21/input/LEAPR/Card17/Nka.hpp"
  #include "njoy21/input/LEAPR/Card17/Dka.hpp"
  Argument < Nka > nka;
  Argument < Dka > dka;

  template< typename Char> 
  Card17( iRecordStream < Char >& iss )
    try:
      nka( argument::extract < Nka > ( iss ) ),
      dka( argument::extract < Dka > ( iss ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card17" );
      throw e;
    }
};
