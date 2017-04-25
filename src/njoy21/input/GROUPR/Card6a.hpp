class Card6a {
public:
  #include "njoy21/input/GROUPR/Card6a/Ngn.hpp"

  Argument< Ngn > ngn;

  template< typename Char >
  Card6a( iRecordStream< Char >& is )
    try:
      ngn( argument::extract< Ngn >( is ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card 6a");
      throw e;
    }
};
