class Card6 {
public:
  #include "njoy21/input/RECONR/Card6/Enode.hpp"

  Argument< Enode > enode;

  template< typename Char >
  Card6( iRecordStream< Char >& is, const Argument< Card3::Ngrid >& ngrid )
    try:
      enode( argument::extract< Enode >(is, ngrid ) ){ Card::clear(is); }
    catch( std::exception& e ) {
      Log::info( "Trouble validating Card6" );
      throw e;
    }
};
