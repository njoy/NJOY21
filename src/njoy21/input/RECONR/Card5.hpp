class Card5 {
public:
  #include "njoy21/input/RECONR/Card5/Cards.hpp"

  Argument< Cards > cards;

  template< typename Istream >
  Card5( Istream& is, long& lineNumber ) :
    Card5( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card5( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      cards( argument::extract< Cards >( is, lineNumber ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 5");
      throw e;
    }

};
