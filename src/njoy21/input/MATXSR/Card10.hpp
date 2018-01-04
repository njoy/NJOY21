class Card10{
public:

  #include "njoy21/input/MATXSR/Card10/Hmat.hpp"
  #include "njoy21/input/MATXSR/Card10/Matno.hpp"
  #include "njoy21/input/MATXSR/Card10/Matgg.hpp"

  Argument< Hmat > hmat;
  Argument< Matno > matno;
  Argument< Matgg > matgg;

  template< typename Istream >
  Card10( Istream& is )
  try:
    hmat( argument::extract< Hmat >( is ) ),
    matno( argument::extract< Matno >( is ) ),
    matgg( argument::extract< Matgg >( is, this->matno.value ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 10." );
    throw e;
  }
};
