class Card3 {
public:
   #include "njoy21/input/RECONR/Card3/Mat.hpp"
   #include "njoy21/input/RECONR/Card3/Ncards.hpp"
   #include "njoy21/input/RECONR/Card3/Ngrid.hpp"

  Argument< Mat > material;
  Argument< Ncards > ncards;
  Argument< Ngrid > ngrid;

  template< typename Istream >
  Card3( Istream& is, long& lineNumber ) :
      Card3( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card3( std::basic_istringstream< Char > && is, const long& lineNumber )
    try:
      material( argument::extract< Mat >( is, lineNumber ) ),
      ncards( argument::extract< Ncards >( is, lineNumber ) ),
      ngrid( argument::extract< Ngrid >( is, lineNumber ) ){}
  catch( std::exception& e ){
    Log::info( "Trouble validating Card3" );
    throw e;
  }
};
