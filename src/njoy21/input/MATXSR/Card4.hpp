class Card4 {
public:

  #include "njoy21/input/MATXSR/Card4/Hsetid.hpp"

  Argument< Hsetid > hsetid;

  template< typename Istream >
  Card4( Istream& is )
  try:
    hsetid( argument::extract< Hsetid >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 4." );
    throw e;
  }
};
