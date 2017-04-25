class Card6b {
public:

  #include "njoy21/input/GROUPR/Card6b/Egn.hpp"

  Argument< Egn > egn;

  template< typename Char >
  Card6b( iRecordStream< Char >& is,
         Argument< GROUPR::Card6a::Ngn >& ngn )
    try:
      egn( argument::extract< Egn >( is, ngn ) ){ 
        Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating card 6b" );
      throw e;
    }
};
