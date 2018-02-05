template< typename Istream >
std::vector< std::pair< Argument< Matn >, Argument< Wtn > > >
                                                 readMatnWtnList( Istream& is ){
  std::vector< std::pair< Argument< Matn >, Argument< Wtn > > > matnWtnList;
  std::vector< int > matnList;

  do{
    try{
      Card::clear( is );
      if( matnWtnList.size() == 0 ){
        Log::error( "No material and associated weighting factors provided." );
        break;
      }
    }
    catch( ... ){
    }

    if( matnList.size() == 10 ){
      Log::error( "Too many matn numbers provided." );
      break;
    }

    auto matn_tmp = argument::extract< MIXR::Card3::Matn >( is );

    auto wtn_tmp = argument::extract< MIXR::Card3::Wtn >( is );

    if( std::find( matnList.begin(), matnList.end(), matn_tmp.value ) == matnList.end() ){
      matnList.push_back( matn_tmp.value );
      matnWtnList.push_back( std::make_pair( std::move( matn_tmp ),
                                             std::move( wtn_tmp ) ) );
    } else {
      Log::error( "MIXR matn number {} used more than once.", matn_tmp.value );
      break;
    }
  }

  throw std::exception();
}
