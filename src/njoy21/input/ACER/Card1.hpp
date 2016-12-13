class Card1 {
public:
  #include "njoy21/input/ACER/Card1/Nendf.hpp"
  #include "njoy21/input/ACER/Card1/Npend.hpp"
  #include "njoy21/input/ACER/Card1/Ngend.hpp"
  #include "njoy21/input/ACER/Card1/Nace.hpp"
  #include "njoy21/input/ACER/Card1/Ndir.hpp"

  Argument< Nendf > nendf;
  Argument< Npend > npend;
  Argument< Ngend > ngend;
  Argument< Nace > nace;
  Argument< Ndir > ndir;

  template< typename Istream >
  Card1( Istream& is, long& lineNumber ) : 
    Card1( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:

  template< typename Char >
  Card1( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      nendf( argument::extract< Nendf >( is, lineNumber ) ),
      npend( argument::extract< Npend >( is, lineNumber, this->nendf ) ),
      ngend( argument::extract< Ngend >( is, lineNumber, 
                                         this->nendf, 
                                         this->npend ) ),
      nace( argument::extract< Nace >( is, lineNumber, 
                                         this->nendf, 
                                         this->npend,
                                         this->ngend ) ),
      ndir( argument::extract< Ndir >( is, lineNumber, 
                                         this->nendf, 
                                         this->npend,
                                         this->ngend,
                                         this->nace ) )
      {}
    catch( std::exception& e ){
      Log::info( "Trouble validating Card1");
      throw e;
    }
};
