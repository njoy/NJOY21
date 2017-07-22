	
template< typename Char >
HEATR( iRecordStream<Char>& is )
  try:
    card1( is ),
    card2( is, this->card1.nplot ),
    card3( buildCard3( is, this->card2 ) ),
    controlTuple( buildControlTuple( is, this->card2 ) ){
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating HEATR input" );
    throw e;
  } 
