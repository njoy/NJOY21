class Card8d {
public:
  #include "njoy21/input/GROUPR/Card8d/Ninwt.hpp"

  Argument< Ninwt > ninwt;

  template< typename Char >
  Card8d( iRecordStream< Char >& is, const Card1& card1 )
    try:
      ninwt( argument::extract< Ninwt >( is, card1 ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card8d");
      throw e;
    }
};
