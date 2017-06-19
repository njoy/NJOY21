class Card1 {
public:
  #include "njoy21/input/VIEWR/Card1/Infile.hpp"
  #include "njoy21/input/VIEWR/Card1/Nps.hpp"
  Argument < Infile > infile;
  Argument < Nps > nps;

  template< typename Char> 
  Card1( iRecordStream < Char >& iss )
    try:
      infile( argument::extract < Infile > ( iss ) ),
      nps( argument::extract < Nps > ( iss, this -> infile ) ) {
        Card::clear( iss );
      }
    catch( std::exception& e) {
      Log::info( "Trouble while validating Card 1" );
      throw e;
    }
};
