class Card4 {
public:
#include "njoy21/input/ACER/Card4/Izaw.hpp"

  Argument< Izaw > izaw;

  template< typename Char >
  Card4( iRecordStream< Char >& is,
         const Argument< ACER::Card2::Nxtra >& nxtra )
    try:
      izaw( argument::extract< Izaw >( is, nxtra ) )
    {
      Card::clear( is );
    }
    catch( std::exception& e ){
      Log::info("Trouble while validating Card 4");
      throw e;
    }
};

