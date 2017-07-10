class Card10 {
public:
  #include "njoy21/input/GROUPR/Card10/Matd.hpp"
  
  Argument< Matd > matd;

  template< typename Char >
  Card10( iRecordStream< Char >& is  )
    try:
      matd( argument::extract< Matd >( is ) ){ Card::clear( is ); }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 10");
      throw e;
    }
};
