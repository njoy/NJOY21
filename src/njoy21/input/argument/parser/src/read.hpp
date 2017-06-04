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

template< typename Char, typename... Args >
bool read( iRecordStream<Char>& is, std::optional<ENDFtk::TAB1>& tab1, Args&&... ){
  double C1;
  double C2;
  int L1;
  int L2;
  int N1;
  int N2;

  is >> C1 >> C2
     >> L1 >> L2
     >> N1 >> N2;

  std::vector< long > NBT;
  std::vector< long > INT;
  NBT.resize(N1);
  INT.resize(N1);
  for( int n = 0; n < N1; ++n ){
    is >> NBT[n] >> INT[n];
  }

  std::vector< double > X; X.resize(N2);
  std::vector< double > Y; Y.resize(N2);
  for( int n = 0; n < N2; ++n ){
    is >> X[n] >> Y[n];
  }
  tab1 = ENDFtk::TAB1( C1, C2, L1, L2,
		       std::make_tuple(NBT, INT),
		       std::make_tuple(X, Y) );
  return true;
}

template< typename Char, typename T, typename... Args >
std::enable_if_t< std::is_default_constructible<T>::value, bool >
read( iRecordStream<Char>& is, std::optional<T>& value, Args&&... args ){
  value = T{};
  return read( is, *value, std::forward<Args>(args)... );
}

template< typename T, typename = void >
struct BasicReadable{
  static constexpr bool value = false;
};

template< typename T >
struct BasicReadable< T, utility::void_t
		      < decltype( std::declval<std::basic_istream<char>&>()
				  >> std::declval<T&>() ) > > {
  static constexpr bool value = true;
};

template< typename T, typename = void >
struct RecordReadable{
  static constexpr bool value = false;
};

template< typename T >
struct RecordReadable< T, utility::void_t
		       < decltype( std::declval<iRecordStream<char>&>()
				   >> std::declval<T&>() ) > > {
  static constexpr bool value = true;
};

template< typename T >
struct Readable {
  static constexpr bool value = BasicReadable<T>::value or RecordReadable<T>::value;
};

template< typename Char, typename T, typename... Args >
std::enable_if_t< Readable<T>::value, bool >
read( iRecordStream<Char>& is, T& i, Args&&... ){
  is >> i; validate(is); return true;
}
