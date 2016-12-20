class Card5 {
public:
  #include "njoy21/input/BROADR/Card5/Mat1.hpp"
  
  Argument< Mat1 > mat1;

  template< typename Char >
  Card5( iRecordStream< Char >& is  )
    try:
      mat1( argument::extract< Mat1 >( is ) ){ Card::clear( is ); }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 5");
      throw e;
    }
};
