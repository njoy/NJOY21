class Card4 {
  public:
  #include "njoy21/input/LEAPR/Card4/Mat.hpp"
  #include "njoy21/input/LEAPR/Card4/Za.hpp"
  #include "njoy21/input/LEAPR/Card4/Isabt.hpp"
  #include "njoy21/input/LEAPR/Card4/Ilog.hpp"

  Argument< Mat   > mat;
  Argument< Za    > za;
  Argument< Isabt > isabt;
  Argument< Ilog  > ilog;

  template< typename Char >
  Card4( iRecordStream<Char>& is )
  try:
    mat  ( argument::extract< Mat   >( is ) ),
    za   ( argument::extract< Za    >( is ) ),
    isabt( argument::extract< Isabt >( is ) ),
    ilog ( argument::extract< Ilog  >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card4" );
    throw e;
  }
};
