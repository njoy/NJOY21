template< typename Istream >
std::vector< std::pair< Argument< Matn >, Argument< Wtn > > >
                              readMatnWtnList( Istream& is, const size_t nnin ){
  std::vector< std::pair< Argument< Matn >, Argument< Wtn > > > matnWtnList;
  std::vector< int > matnList;

  if( nnin > 10 ){
    Log::error( "The maximum number of materials allowed is 10." );
    throw std::exception();
  }

  for( size_t i = 0; i < nnin; i++ ){
    auto matn_tmp = argument::extract< MIXR::Card3::Matn >( is );
    auto wtn_tmp = argument::extract< MIXR::Card3::Wtn >( is );

    if( std::find( matnList.begin(), matnList.end(), matn_tmp.value ) !=
                                                               matnList.end() ){
      Log::error( "MIXR matn number {} used more than once.", matn_tmp.value );
      throw std::exception();
    }

    matnList.push_back( matn_tmp.value );

    matnWtnList.push_back( std::make_pair( std::move( matn_tmp ),
                           std::move( wtn_tmp ) ) );

    Card::clear( is );
  }

  return matnWtnList;
}
