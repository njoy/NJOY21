class Card4 {
public:
  #include "njoy21/input/RECONR/Card4/Err.hpp"
  #include "njoy21/input/RECONR/Card4/Tempr.hpp"
  #include "njoy21/input/RECONR/Card4/Errmax.hpp"
  #include "njoy21/input/RECONR/Card4/Errint.hpp"

  Argument< Err > err;
  Argument< Tempr > tempr;
  Argument< Errmax > errmax;
  Argument< Errint > errint;

  template< typename Istream >
  Card4( Istream& is, long& lineNumber ):
      Card4( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card4( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      err( argument::extract< Err >(is, lineNumber ) ),
      tempr( argument::extract< Tempr >(is, lineNumber ) ),
      errmax( argument::extract< Errmax >(is, lineNumber, err ) ),
      errint( argument::extract< Errint >(is, lineNumber, err ) ){ }
    catch( std::exception& e ){
      Log::info( "Trouble validating Card4" );
      throw e;
    }
      

};
