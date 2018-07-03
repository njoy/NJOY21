template< typename Char >
void echoLine( iRecordStream< Char >& is, const bool backtrack ){
  is.clear();
  const auto index = is.buffer.size();
  const auto& line = is.buffer;
  is.ignore( std::numeric_limits< std::streamsize >::max(), '\n' );
  const auto begin = std::begin( line );
  const auto end = std::end( line );
  const auto position = backtrack ?
    std::find_if( std::make_reverse_iterator( std::next( begin, index ) ),
		  std::make_reverse_iterator( begin ), ::isspace ).base() :
    std::next( begin, index );
  
  utility::echoErroneousLine( begin, position, end, is.lineNumber );
}
