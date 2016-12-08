class Card4 {
public:

  #include "njoy21/input/PURR/Card4/Sigz.hpp"

  Argument< Sigz > sigz;

  template< typename Istream >
  Card4( Istream& is, long& lineNumber,
         Argument< PURR::Card2::Nsigz >& nsigz) :
      Card4( Card::extract( is, lineNumber ), lineNumber, nsigz ){ ++lineNumber; }

private:
  template< typename Char >
  Card4( std::basic_istringstream< Char >&& is, const long& lineNumber,
         Argument< PURR::Card2::Nsigz >& nsigz )
    try:
      sigz( argument::extract< Sigz >( is, lineNumber, nsigz ) )
      {   }
    catch( std::exception& e ){
      Log::info( "Trouble while validating card 4" );
      throw e;
    }
};
