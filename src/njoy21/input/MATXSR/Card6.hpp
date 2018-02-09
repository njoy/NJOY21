class Card6{
public:

  #include "njoy21/input/MATXSR/Card6/Ngrp.hpp"

  Argument< Ngrp > ngrpList;

  template< typename Istream >
  Card6( Istream& is, const unsigned int npart )
  try:
    ngrpList( argument::extract<MATXSR::Card6::Ngrp>( is, npart ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 6." );
    throw e;
  }
};
