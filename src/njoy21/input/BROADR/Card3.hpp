class Card3 {
public:
  #include "njoy21/input/BROADR/Card3/Errthn.hpp"
  #include "njoy21/input/BROADR/Card3/Thnmax.hpp"
  #include "njoy21/input/BROADR/Card3/Errmax.hpp"
  #include "njoy21/input/BROADR/Card3/Errint.hpp"
  
  Argument< Errthn > errthn;
  Argument< Thnmax > thnmax;
  Argument< Errmax > errmax;
  Argument< Errint > errint;

  template< typename Char >
  Card3( iRecordStream< Char >& is )
    try:
      errthn( argument::extract< Errthn >( is ) ),
      thnmax( argument::extract< Thnmax >( is ) ),
      errmax( argument::extract< Errmax >( is, this->errthn ) ),
      errint( argument::extract< Errint >( is, this->errthn ) ){
	Card::clear( is);
    } catch( std::exception& e ){
      Log::info("Trouble while validating Card 3");
      throw e;
    }
};
