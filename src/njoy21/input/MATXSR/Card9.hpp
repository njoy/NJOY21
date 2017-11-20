class Card9{
public:

  #include "njoy21/input/MATXSR/Card9/Joutp.hpp"

  Argument< Joutp > joutp;

  template< typename Istream >
  Card9( Istream& is )
  try:
    joutp( argument::extract< Joutp >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 9." );
    throw e;
  }
};
