class Card8 {

  #include "njoy21/input/WIMSR/Card8/P1flx.hpp"

  Argument< P1flx > p1flx;

  template< typename Istream >
  Card8( iRecordStream< Istream >& is, const unsigned int ngnd,
         const unsigned int jp1 )
  try:
    p1flx( argument::extract< WIMSR::Card8::P1flx >( is ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 8." );
    throw e;
  }
};
