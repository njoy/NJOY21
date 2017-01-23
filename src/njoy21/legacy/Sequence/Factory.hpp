struct Factory {
protected:
    
  using parser =
    std::function
    < std::unique_ptr< interface::Routine >( input::iRecordStream< char >& ) >;

  io::Manager& manager;
  std::unordered_set< std::string >& permittedRoutines;

  #define PAIR( routine ) \
    std::make_pair< std::string, parser >                              \
    ( #routine,                                                        \
      []( auto& inputStream ) -> std::unique_ptr< interface::Routine > \
      { return std::make_unique< routine >( inputStream ); } )
  
  std::unique_ptr< interface::Routine >
  parse( std::string& label, input::iRecordStream< char >& input ){
    static const std::unordered_map< std::string, parser > parserMap =
    { PAIR( MODER ), PAIR( RECONR ), PAIR( BROADR ) };
    return parserMap.at( label )( input );      
  }

  #undef Pair
    
public:
  Factory( io::Manager& manager,
	   std::unordered_set< std::string >& permittedRoutines ) :
    manager( manager ),
    permittedRoutines( permittedRoutines ){}

  std::unique_ptr< interface::Routine::Sequence >
  operator()( std::string& label ){
    using TeeBuffer =
      utility::stream::basic_Tee_streambuf< utility::stream::InputTag, char >;

    auto& input = manager.input();
    auto readBuffer = input.rdbuf();
    try {
      std::vector< std::unique_ptr< interface::Routine > > sequence;
      do {
	{
	  TeeBuffer teeBuffer( readBuffer, manager.buffer().rdbuf() );
	  input.rdbuf( &teeBuffer );
          sequence.push_back( this->parse( label, input ) );
	  input.rdbuf( readBuffer );
	}
        label = input::Label::extract( input );
      } while ( this->permittedRoutines.count( label ) );
      return std::make_unique< Sequence >
	       ( Sequence( manager, std::move( sequence ) ) );
    } catch ( std::exception& e ){
      input.rdbuf( readBuffer );
      throw e;
    }
  }  
};  
