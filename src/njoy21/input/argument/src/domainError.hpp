template< typename Policy, typename Char >
void domainError( iRecordStream< Char >& is ){
  echoLine( is, true );
  Log::info( "\n{}\n", Policy::description() );
}
