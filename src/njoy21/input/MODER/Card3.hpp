class Card3 {
public:
  
#include "njoy21/input/Moder/Card3/Nin.hpp"
#include "njoy21/input/Moder/Card3/Matd.hpp"

  Argument< Nin > nin;
  Argument< Matd > matd;
  
  template< typename Char >
  Card3( iRecordStream< Char >& is,
	 const Argument< Card1::Nout >& nout )
    try:
      nin( argument::extract< Nin >( is, nout ) ),
      matd( argument::extract< Matd >( is ) ){
	if ( this->matd.defaulted ){
	  if ( this->nin.value ){
	    Log::error
	    ("matd argument unspecified on MODER card 3 with nonzero nin argument");
	    argument::domainError< Matd >( is );
	    throw std::exception();
	  }
	} else {
	  if ( not this->nin.value ){
	    Log::error
	    ("matd argument specified on MODER card 3 with zero nin argument");
	    argument::domainError< Matd >( is );
	    throw std::exception();
	  }
    	}
	Card::clear(is);
    } catch( std::exception& e ) {
      Log::info("Trouble while validating Card 3");
      throw e;
    }
};
