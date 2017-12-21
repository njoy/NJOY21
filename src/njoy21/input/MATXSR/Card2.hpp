class Card2 {
public:

  #include "njoy21/input/MATXSR/Card2/Ivers.hpp"
  #include "njoy21/input/MATXSR/Card2/Huse.hpp"

  Argument< Ivers > ivers;
  Argument< Huse > huse;

  template< typename Istream >
  Card2( Istream& is )
  try:
    ivers( argument::extract< Ivers >( is ) ),
    huse( argument::extract< Huse >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 2." );
    throw e;
  }
};
