class Card4 {
public:
  #include "njoy21/input/BROADR/Card4/Temp2.hpp"
  
  Argument< Temp2 > temp2;

  template< typename Char >
  Card4( iRecordStream< Char >& is,
	 const Argument< Card2::Ntemp2 >& ntemp2,
	 const Argument< Card2::Istrap >& istrap,
         const Argument< Card2::Temp1 >& temp1 )
    try:
      temp2( argument::extract< Temp2 >( is, ntemp2, istrap, temp1 ) ){
	Card::clear( is);
    } catch( std::exception& e ) {
      Log::info("Trouble while validating Card 4");
      throw e;
    }
};
