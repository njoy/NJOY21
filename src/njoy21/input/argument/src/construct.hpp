template< typename Policy, typename Data >
std::enable_if_t
< std::is_same< typename Policy::Value_t, Data >::value, Type<Policy> >
construct( Data& data, bool success ){
  return Type<Policy>( std::move(data), success );
}

template< typename Policy, typename Data>
std::enable_if_t
< not std::is_same< typename Policy::Value_t, Data >::value, Type<Policy> >
construct( Data& data, bool success ){
  return Type<Policy>( std::move(*data), success );
}
