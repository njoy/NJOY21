class BROADR {
public:
  /* nested types */
  #include "njoy21/input/BROADR/Card1.hpp"
  #include "njoy21/input/BROADR/Card2.hpp"
  #include "njoy21/input/BROADR/Card3.hpp"
  #include "njoy21/input/BROADR/Card4.hpp"
  #include "njoy21/input/BROADR/Card5.hpp"
  
  /* fields */
  Card1 card1;
  Card2 card2;
  Card3 card3;
  Card4 card4;
  optional< std::vector< Card5 > > card5List;

  /* ctor */
  template< typename Istream >
  BROADR( Istream& is, long& lineNumber )
    try :
      card1( is, lineNumber ),
      card2( is, lineNumber ),
      card3( is, lineNumber ),
      card4( is, lineNumber,
	     this->card2.ntemp2,
	     this->card2.istrap,
	     this->card2.temp1 ){
	Card5 card5( is, lineNumber );
	if ( card5.mat1.value ){
	  this->card5List = std::vector< Card5 >();
	  this->card5List->push_back( std::move(card5) );
	  do {
	    this->card5List->emplace_back( is, lineNumber );
	  } while ( this->card5List->back().mat1.value );
	  this->card5List->pop_back();
	}
    } catch( std::exception& e ){
      Log::info("Trouble while validating BROADR input");
      throw e;
    }
};

