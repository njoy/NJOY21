class Card3 {
public:
#include "njoy21/input/ACER/Card3/Hk.hpp"

  Argument< Hk > hk;

  template< typename Istream >
  Card3( Istream& is, long& lineNumber ) :
    Card3( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card3( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      hk( argument::extract< Hk >( is, lineNumber ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 3");
      throw e;
    }
};
