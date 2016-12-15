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

  template< typename Char >
  Card1( iRecordStream< Char >& is )
    try:
      nendf( argument::extract< Nendf >( is ) ),
      npend( argument::extract< Npend >( is, this->nendf ) ),
      ngend( argument::extract< Ngend >( is, this->nendf, this->npend ) ),
      nace( argument::extract< Nace >( is, this->nendf, 
                                         this->npend,
                                         this->ngend ) ),
      ndir( argument::extract< Ndir >( is, this->nendf, 
                                         this->npend,
                                         this->ngend,
                                         this->nace ) )
      {}
    catch( std::exception& e ){
      Log::info( "Trouble validating Card1");
      throw e;
    }
};
