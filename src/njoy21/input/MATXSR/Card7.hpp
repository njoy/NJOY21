class Card7{
public:

  #include "njoy21/input/MATXSR/Card7/Htype.hpp"

  Argument< Htype > htypeList;

  template< typename Istream >
  Card7( Istream& is, const int ntype )
  try:
    htypeList( argument::extract<MATXSR::Card7::Htype>( is, ntype ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 7." );
    throw e;
  }
};
