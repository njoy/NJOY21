template< typename Istream >
static std::vector< Argument< Mtn > > readMtn( Istream& is ){
  std::vector< Argument< Mtn > > mtnList;
  std::vector< int > usedList;

  do {
    try{
      Card::clear( is );
      if( mtnList.size() == 0 ){
        Log::error( "No values provided for mtn." );
        break;
      }
      return mtnList;
    }
    catch( ... ){
    }

    auto mtn_tmp = argument::extract< MIXR::Card2::Mtn >( is );

    if( std::find( usedList.begin(), usedList.end(), mtn_tmp.value ) == usedList.end() ){
      usedList.push_back( mtn_tmp.value );
      mtnList.push_back( std::move( mtn_tmp ) );
    } else {
      Log::error( "MIXR mt number {} used more than once.", mtn_tmp.value );
      break;
    }

    if( usedList.size() > 20 ){
      Log::error( "Too many mt numbers provided." );
      break;
    }
  }

  throw std::exception();
}
