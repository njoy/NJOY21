class Card4 {
public:
  #include "njoy21/input/BROADR/Card4/Temp2.hpp"
  
  Argument< Temp2 > temp2;

private:
  template< typename Char >
  Card4( std::basic_istringstream< Char >&& is,
	 const long& lineNumber,
         const Argument< Card2::Temp1 >& temp1 )
    try:
      temp2( argument::extract< Temp2 >( is, lineNumber, temp1 ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 4");
      throw e;
    }
  
public:
  template< typename Istream >
  Card4( Istream& is, long& lineNumber, const Argument< Card2::Temp1 >& temp1 ) :
    Card4( Card::extract( is, lineNumber ), lineNumber, temp1 ){ ++lineNumber; }
};
