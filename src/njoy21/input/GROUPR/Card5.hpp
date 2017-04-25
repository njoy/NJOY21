class Card5 {
public:

  #include "njoy21/input/GROUPR/Card5/Sigz.hpp"

  Argument< Sigz > sigz;

  template< typename Char >
  Card5( iRecordStream< Char >& is,
         Argument< GROUPR::Card2::Nsigz >& nsigz )
    try:
      sigz( argument::extract< Sigz >( is, nsigz ) ){ 
        Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating card 4" );
      throw e;
    }
};
