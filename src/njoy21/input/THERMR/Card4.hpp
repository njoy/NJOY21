class Card4 {
public:
  #include "njoy21/input/THERMR/Card4/Tol.hpp"
  #include "njoy21/input/THERMR/Card4/Emax.hpp"
  
  Argument< Tol > tol;
  Argument< Emax > emax;

  template< typename Char >
  Card4( iRecordStream< Char >& is )
    try:
      tol( argument::extract< Tol >( is ) ),
      emax( argument::extract< Emax >( is ) ){
        Card::clear(is);
      } 
      catch( std::exception& e ){
      Log::info("Trouble while validating THERMR Card 4");
      throw e;
    }
};
