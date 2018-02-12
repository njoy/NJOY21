template< typename Istream >
static std::vector< Argument< Mtn > > readMtn( Istream& is ){
  std::vector< Argument< Mtn > > mtnList;
  std::vector< int > usedValues;

  static constexpr size_t nmtmx = 20;

  for( size_t i = 0; i < nmtmx; i++ ){
    auto mtn_tmp = argument::extract< MIXR::Card2::Mtn >( is );

    if( std::find( usedValues.begin(), usedValues.end(),
                                          mtn_tmp.value ) != usedValues.end() ){
      Log::error( "MIXR mtn value {} used more than once.", mtn_tmp.value );
      throw std::exception();
    }

    if( mtn_tmp.value == 0 ) break;

    usedValues.push_back( mtn_tmp.value );

    mtnList.push_back( std::move( mtn_tmp ) );
  }

  if( mtnList.size() == 0 ){
    Log::error( "No values provided for mtn." );
    throw std::exception();
  }

  return mtnList;
}
