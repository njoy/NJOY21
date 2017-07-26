class Card3 {
public:
  #include "njoy21/input/LEAPR/Card3/Ntempr.hpp"
  #include "njoy21/input/LEAPR/Card3/Iprint.hpp"
  #include "njoy21/input/LEAPR/Card3/Nphon.hpp"
  Argument < Ntempr > ntempr;
  Argument < Iprint > iprint;
  Argument < Nphon  > nphon;

  template< typename Char> 
  Card3( iRecordStream < Char >& iss )
    try:
      ntempr( argument::extract < Ntempr > ( iss ) ),
      iprint( argument::extract < Iprint > ( iss ) ),
      nphon(  argument::extract < Nphon  > ( iss ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card 3" );
      throw e;
    }
};
