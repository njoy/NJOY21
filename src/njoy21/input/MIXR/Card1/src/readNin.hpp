template< typename Istream >
static std::vector< Argument< Nin > > readNin( Istream& is, const int nout ){
  std::vector< int > usedValues{ nout };
  std::vector< Argument< Nin > > ninList;

  static constexpr size_t nninmx = 10;

  for( size_t i = 0; i < nninmx; i++ ){
    auto nin_tmp = argument::extract< MIXR::Card1::Nin >( is );

    if( std::find( usedValues.begin(), usedValues.end(),
                              std::abs( nin_tmp.value ) ) != usedValues.end() ){
      Log::error( "MIXR nin value {} used more than once.", nin_tmp.value );
      throw std::exception();
    }

    if( nin_tmp.value == 0 ) break;

    usedValues.push_back( nin_tmp.value );

    ninList.push_back( std::move( nin_tmp ) );
  }

  if( ninList.size() == 0 ){
    Log::error( "No values provided for nin." );
    throw std::exception();
  }

  return ninList;
}
