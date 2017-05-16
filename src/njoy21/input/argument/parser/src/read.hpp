template< typename Char, typename... Args >
bool read( iRecordStream<Char>& is, std::string& string, Args&&... ){
  is >> FortranString<Char>( string );

  bool wasQuoted = (is.buffer.back() == '\'') and ( string.back() != '\'');

  if ( wasQuoted ){
    validate(is);
    if ( is.fail() and ( is.buffer.back() == '\'' ) ){ is.clear(); }
    if ( not is.fail() ){
      string.erase( std::remove( std::begin(string), std::end(string), '\n' ),
		    std::end(string) );
    }
  }
  return true;
}

template< typename Char, typename T, typename Size, typename... Args >
std::conditional_t
< true, std::enable_if_t
  < std::is_default_constructible<T>::value, bool >,
    decltype( int( std::declval< std::decay_t<Size> >() ) ) >
read( iRecordStream<Char>& is, std::vector<T>& vector, Size&& size, Args&&... ){
  vector.resize( size );
  is >> vector;
  return true;
}

template< typename Char, typename T, typename Size, typename... Args >
std::conditional_t
< true, bool, decltype( std::declval< std::decay_t<Size> >().value ) >
read( iRecordStream<Char>& is,
      std::vector<T>& vector,
      Size&& size,
      Args&&... args ){
  return read( is, vector, size.value, std::forward<Args>(args)... );
}

template< typename Char, typename T, typename... Args >
std::enable_if_t< std::is_default_constructible<T>::value, bool >
read( iRecordStream<Char>& is, std::optional<T>& value, Args&&... args ){
  value = T{};
  return read( is, *value, std::forward<Args>(args)... );
}

template< typename Char, typename T, typename... Args >
std::conditional_t
< true, bool,
  decltype( std::declval< iRecordStream<Char>& >() >> std::declval< T& >() ) >
read( iRecordStream<Char>& is, T& i, Args&&... ){
  is >> i; validate(is); return true;
}
