class Card8 {
public:

  #include "njoy21/input/MATXSR/Card8/Jinp.hpp"

  Argument< Jinp > jinp;

  template< typename Istream >
  Card8( Istream& is )
  try:
    jinp( argument::extract< Jinp >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 8." );
    throw e;
  }
};
