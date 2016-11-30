class Label {
public:
  template< typename Istream >
  static auto
  extract( Istream& is, long& lineNumber ){
    std::basic_string< typename Istream::char_type > line;
    auto isComment = []( auto& line ){
      return line.length() > 2
             && line[0] == '-' && line[1] == '-' && line[2] == ' ';
    };
    try {
      do {
	std::getline( is, line );
	++lineNumber;
      } while( isComment( line ) );
      if ( is.eof() && ( utility::string::trim(line) == "" ) ){
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
