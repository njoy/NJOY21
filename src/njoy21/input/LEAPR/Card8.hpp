class Card8 {
  public:
  #include "njoy21/input/LEAPR/Card8/Alpha.hpp"

  Argument< Alpha > alpha;

  template< typename Char >
  Card8( iRecordStream<Char>& is, Argument< LEAPR::Card7::Nalpha >& nalpha )
  try:
    alpha ( argument::extract< Alpha  >( is, nalpha ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card8" );
    throw e;
  }
};
