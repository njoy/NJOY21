class Label {
public:
  template< typename Char >
  static auto
  extract( iRecordStream< Char >& is ){
    std::basic_string< Char > line;
    auto continueReading = []( auto& line ){
      if ( line.length() > 1 && line[0] == '-' && line[1] == '-' ){
	return true;
      }
      return "" == utility::string::trim(line);
    };
    
    try {
      do {
	std::getline( is, line );
      } while( ( not is.eof() ) and continueReading( line ) );
      if ( is.fail() ) { throw std::ios::failure(""); }
    } catch ( std::ios::failure& f ){
      Log::error("Encountered end of input file before reading 'stop' keyword");
      throw f;
    }
    for ( auto& c : line ){ c = toupper(c); }
    auto begin = std::find_if_not( line.begin(), line.end(),
                                   [](auto&& c){ return std::isspace(c); } );
    auto slash = std::find_if( begin, line.end(),
                               [](auto&& c){ return c == '/'; } );
    auto end = std::find_if_not( std::make_reverse_iterator( slash ),
                                 std::make_reverse_iterator( begin ),
                                 [](auto&& c){ return std::isspace(c); } ).base();
    return std::string( begin, end );
  }
};
