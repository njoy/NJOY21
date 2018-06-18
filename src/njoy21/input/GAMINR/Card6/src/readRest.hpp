template< typename Istream >
static optional< std::pair< Argument< Mtd >, Argument< Mtname > > >
readRest( Istream& is, const int mfd ){
  Argument< Mtd > mtd( argument::extract< Mtd >( is ) );
  Argument< Mtname > mtname( argument::extract< Mtname >( is, mfd ) );

  if( mfd == -1 ){
    return std::nullopt;
  }
  else{
    return std::make_pair( std::move( mtd ), std::move( mtname ) );
  }
}
