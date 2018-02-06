class Material {
  public:
  std::vector< Card6 > card6;
  Card7 card7;

  template< typename Istream >
  Material( Istream& is )
  try:
    card6( readCard6List( is ) ),
    card7( is )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating GAMINR Material input (Card6-7)." );
    throw e;
  }
};
