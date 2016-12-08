class Card3 {
public:
  /* nested types */
  #include "njoy21/input/PURR/Card3/Temp.hpp"

  Argument< Temp > temp;

  template< typename Istream >
  Card3( Istream& is, long& lineNumber ) :
      Card3( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card3( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      temp( argument::extract< Temp >( is, lineNumber ) )
      {   }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 3" );
      throw e;
    }
};
