class Card2 {
public:
  #include "njoy21/input/ACER/Card2/Iopt.hpp"
  #include "njoy21/input/ACER/Card2/Iprint.hpp"

  Argument< Iopt > iopt;
  Argument< Iprint > iprint;

  template< typename Istream >
  Card2( Istream& is, long& lineNumber ) : 
    Card2( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:

  template< typename Char >
  Card2( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      iopt( argument::extract< Iopt >( is, lineNumber ) ),
      iprint( argument::extract< Iprint >( is, lineNumber ) )
    {   }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card2");
      throw e;
    }
};
