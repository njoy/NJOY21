class Card1 {
public:
#include "njoy21/input/RECONR/Card1/Nendf.hpp"
#include "njoy21/input/RECONR/Card1/Npend.hpp"

  Argument< Nendf > nendf;
  Argument< Npend > npend;
  
  template< typename Istream >
  Card1( Istream& is, long& lineNumber ) : 
    Card1( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:

  template< typename Char >
  Card1( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      nendf( argument::extract< Nendf >( is, lineNumber ) ),
      npend( argument::extract< Npend >( is, lineNumber, this->nendf ) ){}
    catch( std::exception& e ){
      Log::info( "Trouble validating Card1");
      throw e;
    }
};
