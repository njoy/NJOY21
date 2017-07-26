class Card2 {
public:
  #include "njoy21/input/LEAPR/Card2/Title.hpp"
  Argument < Title > title;

  template< typename Char> 
  Card2( iRecordStream < Char >& iss )
    try:
      title( argument::extract < Title > ( iss ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card 2" );
      throw e;
    }
};
