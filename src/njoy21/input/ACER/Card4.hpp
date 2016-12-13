class Card4 {
public:
#include "njoy21/input/ACER/Card4/Izaw.hpp"

  Argument< Izaw > izaw;

  template< typename Istream >
  Card4( Istream& is, long& lineNumber ) :
    Card4( Card::extract( is, lineNumber ), lineNumber ){ ++lineNumber; }

private:
  template< typename Char >
  Card4( std::basic_istringstream< Char >&& is, const long& lineNumber )
    try:
      izaw( argument::extract< Izaw >( is, lineNumber ) ){}
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 4");
      throw e;
    }
};

