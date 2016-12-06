class Card2 {
public:

  /* nested types */
  #include "njoy21/input/PURR/Card2/Ntemp.hpp"
  #include "njoy21/input/PURR/Card2/Nsigz.hpp"
  #include "njoy21/input/PURR/Card2/Nbin.hpp"
  #include "njoy21/input/PURR/Card2/Nladr.hpp"
  #include "njoy21/input/PURR/Card2/Iprint.hpp"
  #include "njoy21/input/PURR/Card2/Nunx.hpp"

  Argument< argument::common::Matd > matd;
  Argument< Ntemp > ntemp;
  Argument< Nsigz > nsigz;
  Argument< Nbin > nbin;
  Argument< Nladr > nladr;
  Argument< Iprint > iprint;
  Argument< Nunx > nunx;

  template< typename Istream >
  Card2( Istream& is, long& lineNumber ) :
      Card2( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card2( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      matd( argument::extract< argument::common::Matd >( is, lineNumber ) ),
      ntemp( argument::extract< Ntemp >( is, lineNumber ) ),
      nsigz( argument::extract< Nsigz >( is, lineNumber ) ),
      nbin( argument::extract< Nbin >( is, lineNumber ) ),
      nladr( argument::extract< Nladr >( is, lineNumber ) ),
      iprint( argument::extract< Iprint >( is, lineNumber ) ),
      nunx( argument::extract< nunx >( is, lineNumber ) )
      {   }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 2" );
      throw e;
    }
};
