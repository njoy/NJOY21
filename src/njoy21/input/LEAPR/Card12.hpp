class Card12 {
public:
  #include "njoy21/input/LEAPR/Card12/Rho.hpp"

  Argument < Rho > rho;

  template< typename Char> 
  Card12( iRecordStream < Char >& iss, Argument< LEAPR::Card11::Ni >& ni )
    try:
      rho( argument::extract < Rho > ( iss, ni ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card 12" );
      throw e;
    }
};
