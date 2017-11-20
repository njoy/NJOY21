class Card7{
public:

  #include "njoy21/input/MATXSR/Card7/Htype.hpp"

  Argument< Htype > htype;

  template< typename Istream >
  Card7( Istream& is )
  try:
    htype( argument::extract< Htype >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 7." );
    throw e;
  }
};
