class Card6 {
  public:
  #include "njoy21/input/LEAPR/Card6/Nss.hpp"
  #include "njoy21/input/LEAPR/Card6/B7.hpp"
  #include "njoy21/input/LEAPR/Card6/Aws.hpp"
  #include "njoy21/input/LEAPR/Card6/Sps.hpp"
  #include "njoy21/input/LEAPR/Card6/Mss.hpp"

  struct ControlTuple {
    Argument< B7  > b7;  
    Argument< Aws > aws;  
    Argument< Sps > sps;  
    Argument< Mss > mss;  
  };
  
  #include "njoy21/input/LEAPR/Card6/src/buildControlTuple.hpp"

  Argument< Nss > nss;
  optional<ControlTuple> controlTuple; 

  template< typename Char >
  Card6( iRecordStream<Char>& is )
  try:
    nss( argument::extract< Nss >( is ) ),
    controlTuple( buildControlTuple( is, this->nss ) )
  {
    if( nss.value == 0 ){
      try{ Card::clear( is ); }
      catch( std::exception& e ){
        Log::info( "If no secondary scatterer is indicated (nss = 0), then\n"
                   "no other Card6 inputs are necessary." );
        throw e;
      }
    }
    else{
      try{ Card::clear( is ); }
      catch( std::exception& e ){
        throw e;
      }
    }
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card6" );
    throw e;
  }
};
