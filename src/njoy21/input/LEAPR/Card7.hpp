class Card7 {
  public:
  #include "njoy21/input/LEAPR/Card7/Nalpha.hpp"
  #include "njoy21/input/LEAPR/Card7/Nbeta.hpp"
  #include "njoy21/input/LEAPR/Card7/Lat.hpp"

  Argument< Nalpha > nalpha;
  Argument< Nbeta  > nbeta;
  Argument< Lat    > lat;

  template< typename Char >
  Card7( iRecordStream<Char>& is )
  try:
    nalpha( argument::extract< Nalpha >( is ) ),
    nbeta ( argument::extract< Nbeta  >( is ) ),
    lat   ( argument::extract< Lat    >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card7" );
    throw e;
  }
};
