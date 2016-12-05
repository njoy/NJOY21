class Card6 {
public:
  #include "njoy21/input/RECONR/Card6/Enode.hpp"

  Argument< Enode > enode;

  template< typename Istream >
  Card6( Istream& is, long& lineNumber, 
         Argument< RECONR::Card3::Ngrid> & ngrid ):
      Card6( Card::extract( is, lineNumber ), lineNumber, ngrid )
  { ++lineNumber; }

private:
  template< typename Char >
  Card6( std::basic_istringstream< Char >&& is, 
         const long& lineNumber, 
         Argument< RECONR::Card3::Ngrid >& ngrid )
    try:
      enode( argument::extract< Enode >(is, lineNumber, ngrid ) ){ }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card6" );
      throw e;
    }
};
