class Card2 {
public:
  /* nested types */
  #include "njoy21/input/PURR/Card2/Ntemp.hpp"
  #include "njoy21/input/PURR/Card2/Nsigz.hpp"
  #include "njoy21/input/UNRESR/Card2/Iprint.hpp"

  Argument< RECONR::Card3::Mat > matd;
  Argument< PURR::Card2::Ntemp > ntemp;
  Argument< PURR::Card2::Nsigz > nsigz;
  Argument< Iprint > iprint;

  template< typename Istream >
  Card2( Istream& is, long& lineNumber ) :
      Card2( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card2( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      matd( argument::extract< RECONR::Card3::Mat >( is, lineNumber ) ),
      ntemp( argument::extract< PURR::Card2::Ntemp >( is, lineNumber ) ),
      nsigz( argument::extract< PURR::Card2::Nsigz >( is, lineNumber ) ),
      iprint( argument::extract< Iprint >( is, lineNumber ) )
      {   }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 2" );
      throw e;
    }
};
