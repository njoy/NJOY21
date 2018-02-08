template< typename Istream >
std::vector< Card3 > readCard3List( Istream& is ){
  std::vector< Card3 > card3List;
  std::vector< int > matList;

  do{
    card3List.emplace_back( is );
    if( std::find( matList.begin(), matList.end(), card3List.back().mt.value ) != matList.end() ){
      Log::error( "Same material number ({}) provided twice.",
                                                    card3List.back().mt.value );
      throw std::exception();
    } else if( card3List.back().mt.value != 0 ){
      matList.push_back( card3List.back().mt.value );
    }
  } while( card3List.back().mt.value != 0 );

  card3List.pop_back();

  if( card3List.empty() ){
    Log::error( "No real material values provided." );
    throw std::exception();
  } else if( card3List.size() > 5 ){
    Log::error( "Too many materials ( >5 ) provided." );
    throw std::exception();
  }

  return card3List;
}
