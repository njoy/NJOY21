class Card5 {
public:

  #include "njoy21/input/RESXSR/Card5/Hmat.hpp"
  #include "njoy21/input/RESXSR/Card5/Mat.hpp"
  #include "njoy21/input/RESXSR/Card5/Unit.hpp"

  Argument< Hmat > hmat;
  Argument< Mat > mat;
  Argument< Unit > unit;

  template< typename Istream >
  Card5( Istream& is )
  try:
    hmat( argument::extract< Hmat >( is ) ),
    mat( argument::extract< Mat >( is ) ),
    unit( argument::extract< Unit >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating Card5." );
    throw e;
  }
};
