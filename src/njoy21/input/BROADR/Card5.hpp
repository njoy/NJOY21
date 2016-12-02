class Card5 {
public:
  #include "njoy21/input/BROADR/Card5/Mat1.hpp"
  
  Argument< Mat1 > mat1;

private:
  template< typename Char >
  Card5( std::basic_istringstream< Char >&& is,
	 const long& lineNumber )
    try:
      mat1( argument::extract< Mat1 >( is, lineNumber ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 5");
      throw e;
    }
  
public:
  template< typename Istream >
  Card5( Istream& is, long& lineNumber ) :
    Card5( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }
};
