class Card5 {
  public:
  #include "njoy21/input/LEAPR/Card5/Awr.hpp"
  #include "njoy21/input/LEAPR/Card5/Spr.hpp"
//  #include "njoy21/input/LEAPR/Card5/Isabt.hpp"
//  #include "njoy21/input/LEAPR/Card5/Ilog.hpp"

  Argument< Awr   > awr;
  Argument< Spr    > spr;
//  Argument< Isabt > isabt;
//  Argument< Ilog  > ilog;

  template< typename Char >
  Card5( iRecordStream<Char>& is )
  try:
    awr  ( argument::extract< Awr   >( is ) ),
    spr   ( argument::extract< Spr    >( is ) )
//    isabt( argument::extract< Isabt >( is ) ),
//    ilog ( argument::extract< Ilog  >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble while validating LEAPR Card5" );
    throw e;
  }
};
