template< typename Istream >
static optional< std::pair< Argument< Mtd >, Argument< Mtname > > >
readRest( Istream& is, const int mfd ){
  if( mfd == -1 ){
    try{
      Argument< Mtd > mtd( argument::extract< Mtd >( is ) );
      Argument< Mtname > mtname( argument::extract< Mtname >( is, mfd ) );
    }
    catch( ... ){}

    return std::nullopt;
  }

  Argument< Mtd > mtd( argument::extract< Mtd >( is ) );
  Argument< Mtname > mtname( argument::extract< Mtname >( is, mfd ) );

  return std::make_pair( std::move( mtd ), std::move( mtname ) );
}
