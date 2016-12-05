class Card1 {
public:
  #include "njoy21/input/BROADR/Card1/Nendf.hpp"
  #include "njoy21/input/BROADR/Card1/Nin.hpp"
  #include "njoy21/input/BROADR/Card1/Nout.hpp"

  
  Argument< Nendf > nendf;
  Argument< Nin > nin;
  Argument< Nout > nout;

private:
  template< typename Char >
  Card1( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      nendf( argument::extract< Nendf >( is, lineNumber ) ),
      nin( argument::extract< Nin >( is, lineNumber, this->nendf ) ),
      nout( argument::extract< Nout >
	    ( is, lineNumber, this->nendf, this->nin ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 1");
      throw e;
    }
  
public:
  template< typename Istream >
  Card1( Istream& is, long& lineNumber ) :
    Card1( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }
};
