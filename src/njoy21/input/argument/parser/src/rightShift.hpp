template< typename Char, typename Unit, typename MagnitudeType >
iRecordStream<Char>&
operator>>( iRecordStream<Char>& is, Quantity< Unit, MagnitudeType >& quantity ){
  is >> quantity.value; return is;
}

template< typename Char, typename First, typename Second >
iRecordStream<Char>&
operator>>( iRecordStream<Char>& is, std::pair< First, Second >& pair ){
  is >> pair.first;
  validate(is);
  if ( is.good() ){ is >> pair.second; }
  return is;
}

template< typename Char, typename Value >
std::enable_if_t
< std::is_default_constructible<Value>::value, iRecordStream<Char>& >
operator>>( iRecordStream<Char>& is, std::vector< Value >& vector ){
  for ( auto& entry : vector ){
    is >> entry;
    validate(is);
    if ( is.fail() ){
      vector.pop_back();
      break;
    }
  }
  return is;
}

template< typename Char >
std::basic_istream<Char>&
operator>>( std::basic_istream< Char >& is, FortranString<Char> string ){
  string.read(is); return is;
}
