class Card {
  template< typename Char >
  using IStream = utility::stream::basic_RecordOrientedStream
                  < std::basic_istream, Char >;
  
public:

  template< typename Char >
  static void
  clear( IStream< Char >& is ){
    const auto& line = is.buffer;
    const auto position = line.size();
    is.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    auto it = std::find_if_not( std::next( std::begin( line ), position ),
				std::end( line ),
			        []( auto c ){ return std::isspace(c); } );
    if ( it == std::end( line ) || *it == '/' ){ return; }
    Log::error( "Encountered unexpected argument" );
    utility::echoErroneousLine( std::begin( line ), it,
				std::end(line), is.lineNumber );
    throw std::exception();
  }
};
