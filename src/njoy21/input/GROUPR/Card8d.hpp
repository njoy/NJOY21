class Card8d {
public:
  #include "njoy21/input/GROUPR/Card8d/Ninwt.hpp"

  Argument< Ninwt > ninwt;

  template< typename Char >
  Card8d( iRecordStream< Char >& is )
    try:
      ninwt( argument::extract< Ninwt >( is ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card8d");
      throw e;
    }
};
