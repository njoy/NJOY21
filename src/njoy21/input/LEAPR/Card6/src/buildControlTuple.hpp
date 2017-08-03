
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


