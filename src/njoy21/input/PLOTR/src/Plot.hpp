class Plot {
  public:
  Card3 card3;
  Card3a card3a;
  Card4 card4;
  Card5 card5;
  Card5a card5a;
  Card6 card6;
  Card6a card6a;
  optional< std::pair< Card7, Card7a > > card7;

  template< typename Istream >
  Plot( Istream& is )
  try:
    card3( is ),
    card3a( is ),
    card4( is ),
    card5( is, this->card4.xtag, this->card4.itype, this->card4.ileg.value ),
    card5a( is ),
    card6( is, this->card4.itype, this->card4.ytag, this->card4.ileg.value ),
    card6a( is ),
    card7( readCard7( is, this->card4.jtype.value ) )
  {
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating PLOTR Plot input\n"
               "(Card3-7a)." );
    throw e;
  }
};
