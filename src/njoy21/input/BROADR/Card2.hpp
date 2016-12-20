class Card2 {
public:
  #include "njoy21/input/BROADR/Card2/Mat1.hpp"
  #include "njoy21/input/BROADR/Card2/Ntemp2.hpp"
  #include "njoy21/input/BROADR/Card2/Istart.hpp"
  #include "njoy21/input/BROADR/Card2/Istrap.hpp"
  #include "njoy21/input/BROADR/Card2/Temp1.hpp"
  
  Argument< Mat1 > mat1;
  Argument< Ntemp2 > ntemp2;
  Argument< Istart > istart;
  Argument< Istrap > istrap;
  Argument< Temp1 > temp1;

  template< typename Char >
  Card2( iRecordStream< Char >& is )
    try:
      mat1( argument::extract< Mat1 >( is ) ),
      ntemp2( argument::extract< Ntemp2 >( is ) ),
      istart( argument::extract< Istart >( is ) ),
      istrap( argument::extract< Istrap >( is ) ),
      temp1( argument::extract< Temp1 >( is ) ){
	Card::clear(is);
    } catch( std::exception& e ){
      Log::info("Trouble while validating Card 2");
      throw e;
    }
};
