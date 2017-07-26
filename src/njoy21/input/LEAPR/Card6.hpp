class Card6 {
  public:
  #include "njoy21/input/LEAPR/Card6/Nss.hpp"
  #include "njoy21/input/LEAPR/Card6/B7.hpp"
  #include "njoy21/input/LEAPR/Card6/Aws.hpp"
  #include "njoy21/input/LEAPR/Card6/Sps.hpp"
  #include "njoy21/input/LEAPR/Card6/Mss.hpp"
  
  using ControlTuple = std::tuple< Argument< B7  >, Argument< Aws >, 
                                   Argument< Sps >, Argument< Mss > >;

  Argument< Nss > nss;
  optional<ControlTuple> controlTuple; 

  static optional<ControlTuple> buildControlTuple( 
    iRecordStream<char>& is, const Argument< Nss >& nss ){
	  
    if( nss.value == 1 ){
      auto b7  = argument::extract< B7  >( is );
      auto aws = argument::extract< Aws >( is );
      auto sps = argument::extract< Sps >( is );
      auto mss = argument::extract< Mss >( is );
      return ControlTuple( b7, aws, sps, mss );
    }   
    
    return std::nullopt;
  }

  template< typename Char >
  Card6( iRecordStream<Char>& is )
  try:
    nss( argument::extract< Nss >( is ) ),
    controlTuple( buildControlTuple( is, this->nss ) )
  {
    // If nss == 0 and line is not clear, inform user that nss == 0 
    // must be used with an otherwise empty line
    if( nss.value == 0 ){
      try{ Card::clear( is ); }
      catch( std::exception& e ){
        Log::info( "If the existence of a secondary scatterer is indicated\n"
		   "(nss = 1), then all subsequent Card6 inputs are required" );
	throw e;
      }
    }
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card6" );
    throw e;
  }
};
