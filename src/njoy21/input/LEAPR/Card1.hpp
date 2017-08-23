class Card1 {
public:
  struct Nout : public argument::common::Nout {
    static bool verify( argument::common::Nout::Value_t v ){
      return argument::common::Nout::verify( v );
    }
  };
  
  Argument < Nout > nout;

  template< typename Char> 
  Card1( iRecordStream < Char >& iss )
    try:
      nout( argument::extract < Nout > ( iss ) ){
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card 1" );
      throw e;
    }
};
