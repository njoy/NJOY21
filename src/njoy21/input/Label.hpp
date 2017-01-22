class Label {
public:
  template< typename Char >
  static auto
  extract( iRecordStream< Char >& is ){
    std::basic_string< Char > line;
    auto continueReading = []( auto& line ){
      if ( line.length() > 2
	   && line[0] == '-' && line[1] == '-' && line[2] == ' ' ){
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
    return utility::string::trim( line );
  }
};
