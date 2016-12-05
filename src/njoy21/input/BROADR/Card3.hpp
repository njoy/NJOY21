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
  
private:
  template< typename Char >
  Card3( std::basic_istringstream< Char >&& is,
	 const long& lineNumber )
    try:
      errthn( argument::extract< Errthn >( is, lineNumber ) ),
      thnmax( argument::extract< Thnmax >( is, lineNumber ) ),
      errmax( argument::extract< Errmax >( is, lineNumber, this->errthn ) ),
      errint( argument::extract< Errint >( is, lineNumber, this->errthn ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3");
      throw e;
    }
  
public:
  template< typename Istream >
  Card3( Istream& is, long& lineNumber ) :
    Card3( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }
};
