class Card2 {
public:
#include "njoy21/input/RECONR/Card2/Tlabel.hpp"

  Argument< Tlabel > tlabel;

private:
  template< typename Char >
  Card2( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      tlabel( argument::extract< Tlabel >( is, lineNumber ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 2");
      throw e;
    }
  
public:
  template< typename Istream >
  Card2( Istream& is, long& lineNumber ) :
    Card2( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }
};
