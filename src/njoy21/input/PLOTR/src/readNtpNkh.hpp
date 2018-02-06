template< typename Char >
optional< std::pair< Argument< Ntp >, Argument< Nkh > > >
  readNtpNkh( iRecordStream< Char >& is, const int mfd, const int iverf){

    if( ( mfd == 6 and iverf != 1 )
     or ( mfd == 3 and iverf == 1 )
     or ( mfd == 7 ) ){
      auto ntp = argument::extract< Ntp >( is, mfd, iverf );
      return std::make_pair< Argument< Ntp >, 
                             Argument< Nkh > >( std::move(ntp),
                                         argument::extract< Nkh >( 
                                         is, mfd, iverf ) );
    } else {
      return std::nullopt;
    }
  }
