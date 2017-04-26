class Card7b {
public:

  #include "njoy21/input/GROUPR/Card7b/Egg.hpp"

  Argument< Egg > egg;

  template< typename Char >
  Card7b( iRecordStream< Char >& is,
         Argument< GROUPR::Card6a::Ngn >& ngn )
    try:
      egg( argument::extract< Egg >( is, ngn.value+1 ) ){ 
        Card::clear( is );
    } catch( std::exception& e ) {
      Log::info( "Trouble while validating card 7b" );
      throw e;
    }
};
