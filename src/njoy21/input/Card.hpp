class Card {
  template< typename Iterator >
  static void quotation( Iterator& position, const Iterator& end ){
    position = std::find_if( position, end, []( auto c ){ return c == '\''; } );
    if ( position == end ){
      Log::error("Encountered unterminated string argument");
      throw std::exception();
    }
    ++position;
  }
  
  template< typename Iterator >
  static void standard( Iterator& position, const Iterator& end ){
    while ( true ){
      position =
	std::find_if( position, end,
		      []( auto c ){ return c == '\'' || c == '/'; } );
      if ( *position != '\''){ break; }
      quotation( ++position, end );
    }
  }
  
public:
  template< typename Istream >
  static auto
  extract( Istream& is, const long& lineNumber ){
    using char_type = typename Istream::char_type;
    std::basic_string< char_type > line;
    try { std::getline( is, line ); } catch ( std::ios::failure& f ){
      Log::error("Encountered end of file where additional input was expected");
      throw f;
    }
    const auto begin = std::begin( line );
    auto position = begin;
    const auto end = std::end( line );
    try {
      standard( position, end );
      position =
	std::find_if_not( std::make_reverse_iterator(position),
			  std::make_reverse_iterator(begin),
			  []( auto c ){ return std::isspace(c); } ).base();
      return std::basic_istringstream< char_type >
	( std::basic_string< char_type >( begin, position ) );
    } catch ( std::exception& e ){
      utility::echoErroneousLine( begin, position, end, lineNumber );
      throw e;
    }
  }
};
