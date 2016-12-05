class Label {
public:
  template< typename Istream >
  static auto
  extract( Istream& is, long& lineNumber ){
    std::basic_string< typename Istream::char_type > line;
    auto continueReading = []( auto& line ){
      if ( line.length() > 2
	   && line[0] == '-' && line[1] == '-' && line[2] == ' ' ){
	return true;
      }
      return "" == utility::trim(line);
    };
    
    try {
      do {
	std::getline( is, line );
	++lineNumber;
      } while( continueReading( line ) );
      if ( is.fail() ) ){
	throw std::ios::failure("");
      }
    } catch ( std::ios::failure& f ){
      Log::error("Encountered end of input file before reading 'stop' keyword");
      throw f;
    }
    for ( auto & c : line ){ c = toupper(c); }
    return utility::string::trim( line );
  }
};
