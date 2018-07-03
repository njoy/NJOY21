template< typename Policy, typename Char, typename... Args >
auto extract( iRecordStream< Char >& is, Args&&... args ){
  using Parser = typename parser::Type< Policy >;
  typename Parser::Value_t value;
  try {
    bool success = not Parser::read( is, value, std::forward<Args>(args)... );
    return construct< Policy >( value, success );
  } catch ( std::ios_base::failure& f ){
    Log::error( "Failed to read {} from input", Policy::name() );
    echoLine( is, false );
    throw f;
  } catch ( std::domain_error& de ){
    Log::error( "Encountered invalid value for {}", Policy::name() );
    echoLine( is, true );
    Log::info( "\n{}\n", Policy::description() );
    throw de;
  }
}


