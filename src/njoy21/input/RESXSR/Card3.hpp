class Card3 {
public:

  #include "njoy21/input/RESXSR/Card3/Huse.hpp"
  #include "njoy21/input/RESXSR/Card3/Ivers.hpp"

  Argument< Huse > huse;
  Argument< Ivers > ivers;

  template< typename Istream >
  Card3( Istream& is )
  try:
    huse( argument::extract< Huse >( is ) ),
    ivers( argument::extract< Ivers >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating Card2." );
    throw e;
  }
};
