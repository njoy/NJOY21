template< typename Istream >
optional< Card8 > readCard8( Istream& is, optional< Card2a > card2a,
                             const int jp1 ){
  if( jp1 <= 0 ){
    return std::nullopt;
  } else if( card2a != std::nullopt ){
    return Card8( is, card2a->ngnd.value, jp1 );
  } else {
    Log::error(  "User specified neutron current spectrum transport correction\n"
                "was requested (Card4::Jp1 > 0), but no Card2a was given\n"
                "providing the number of groups." );
    throw std::exception();
  }
}
