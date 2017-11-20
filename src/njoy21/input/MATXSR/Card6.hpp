class Card6{
public:

  #include "njoy21/input/MATXSR/Card6/Ngrp.hpp"

  Argument< Ngrp > ngrp;

  template< typename Istream >
  Card6( Istream& is )
  try:
    ngrp( argument::extract< Ngrp >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble reading Card 6." );
    throw e;
  }
};
