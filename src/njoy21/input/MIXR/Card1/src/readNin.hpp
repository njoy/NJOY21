template< typename Istream >
static std::vector< Argument< Nin > > readNin( Istream& is, const int nout ){
  std::vector< int > usedValues{ nout };
  std::vector< Argument< Nin > > ninList;

  do {
    try{
      Card::clear( is );
      if( ninList.size() == 0 ){
        Log::error( "No values provided for nin." );
        throw std::exception();
      }
      return ninList;
    }
    catch( ... ){
    }

    auto nin_tmp = argument::extract< MIXR::Card1::Nin >( is );

    if( std::find( usedValues.begin(), usedValues.end(),
                              std::abs( nin_tmp.value ) ) == usedValues.end() ){
      usedValues.push_back( std::abs( nin_tmp.value ) );
      ninList.push_back( std::move( nin_tmp ) );
    } else {
      Log::error( "MIXR unit {} used more than once.", nin_tmp.value );
      throw std::exception();
    }

    if( usedValues.size() > 11 ){
      Log::error( "Too many unit values provided." );
      throw std::exception();
    }
  }
}
