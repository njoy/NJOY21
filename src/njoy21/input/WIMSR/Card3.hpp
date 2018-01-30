class Card3 {
public:

  using Mat = argument::common::Matd;
  #include "njoy21/input/WIMSR/Card3/Nfid.hpp"
  #include "njoy21/input/WIMSR/Card3/Rdfid.hpp"
  #include "njoy21/input/WIMSR/Card3/Iburn.hpp"

  Argument< Mat > mat;
  Argument< Nfid > nfid;
  Argument< Rdfid > rdfid;
  Argument< Iburn > iburn;

  template< typename Istream >
  Card3( iRecordStream< Istream >& is )
  try:
    mat( argument::extract< WIMSR::Card3::Mat >( is ) ),
    nfid( argument::extract< WIMSR::Card3::Nfid >( is ) ),
    rdfid( argument::extract< WIMSR::Card3::Rdfid >( is ) ),
    iburn( argument::extract< WIMSR::Card3::Iburn >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card3." );
    throw e;
  }
};
