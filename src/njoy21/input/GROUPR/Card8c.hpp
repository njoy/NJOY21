class Card8c {
public:
  #include "njoy21/input/GROUPR/Card8c/Eb.hpp"
  #include "njoy21/input/GROUPR/Card8c/Tb.hpp"
  #include "njoy21/input/GROUPR/Card8c/Ec.hpp"
  #include "njoy21/input/GROUPR/Card8c/Tc.hpp"

  Argument< Eb > eb;
  Argument< Tb > tb;
  Argument< Ec > ec;
  Argument< Tc > tc;

  template< typename Char >
  Card8c( iRecordStream< Char >& is )
    try:
      eb( argument::extract< Eb >( is ) ),
      tb( argument::extract< Tb >( is ) ),
      ec( argument::extract< Ec >( is ) ),
      tc( argument::extract< Tc >( is ) )
    {   
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card8c");
      throw e;
    }
};
