class Card2 {
public:
  #include "njoy21/input/ACER/Card2/Iopt.hpp"
  #include "njoy21/input/ACER/Card2/Iprint.hpp"
  #include "njoy21/input/ACER/Card2/Itype.hpp"
  #include "njoy21/input/ACER/Card2/Suff.hpp"
  #include "njoy21/input/ACER/Card2/Nxtra.hpp"

  Argument< Iopt > iopt;
  Argument< Iprint > iprint;
  Argument< Itype > itype;
  Argument< Suff > suff;
  Argument< Nxtra > nxtra;

  template< typename Istream >
  Card2( Istream& is, long& lineNumber ) : 
    Card2( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:

  template< typename Char >
  Card2( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      iopt( argument::extract< Iopt >( is, lineNumber ) ),
      iprint( argument::extract< Iprint >( is, lineNumber ) ),
      itype( argument::extract< Itype >( is, lineNumber ) ),
      suff( argument::extract< Suff >( is, lineNumber ) ),
      nxtra( argument::extract< Nxtra >( is, lineNumber ) )
    {   }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card2");
      throw e;
    }
};
