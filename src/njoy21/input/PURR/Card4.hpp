class Card4 {
public:

  #include "njoy21/input/PURR/Card4/Sigz.hpp"

  Argument< Sigz > sigz;

  template< typename Char >
  Card4( iRecordStream< Char >& is,
         Argument< PURR::Card2::Nsigz >& nsigz )
    try:
      sigz( argument::extract< Sigz >( is, nsigz ) )
  {   
    Card::clear( is );
  }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 4" );
      throw e;
    }
};
