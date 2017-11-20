class Card5 {
public:

  #include "njoy21/input/MATXSR/Card5/Hpart.hpp"

  Argument< Hpart > hpart;

  template< typename Istream >
  Card5( Istream& is )
  try:
    hpart( argument::extract< Hpart >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 5." );
    throw e;
  }
};
