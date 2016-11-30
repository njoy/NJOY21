class Card3 {
public:
  
#include "njoy21/input/Moder/Card3/Nin.hpp"
#include "njoy21/input/Moder/Card3/Matd.hpp"

  Argument< Nin > nin;
  Argument< Matd > matd;
  
private:
  template< typename Char >
  Card3( std::basic_istringstream< Char >&& is,
	 const long& lineNumber, const Argument< Card1::Nout >& nout )
    try:
      nin( argument::extract< Nin >( is, lineNumber, nout ) ),
      matd( argument::extract< Matd >( is, lineNumber ) ){
	if ( this->matd.defaulted ){
	  if ( this->nin.value ){
	    Log::error
	    ("matd argument unspecified on MODER card 3 with nonzero nin argument");
	    argument::domainError< Matd >( is, lineNumber );
	    throw std::exception();
	  }
	} else {
	  if ( not this->nin.value ){
	    Log::error
	    ("matd argument specified on MODER card 3 with zero nin argument");
	    argument::domainError< Matd >( is, lineNumber );
	    throw std::exception();
	  }
    	}
    } catch( std::exception& e ) {
      Log::info("Trouble while validating Card 3");
      throw e;
    }
  
public:
  template< typename Istream >
  Card3( Istream& is, long& lineNumber, const Argument< Card1::Nout >& nout ) :
    Card3( Card::extract( is, lineNumber ), lineNumber, nout ){ ++lineNumber; }
};
