class Card1 {
public:

  using Nout = argument::common::Nin;

  Argument< Nout > nout;

  template< typename Istream >
  Card1( Istream& is )
  try:
    nout( argument::extract< Nout >( is ) )
  {
    Card::clear( is );
  }
  catch( std::exception& e ){
    Log::info( "Trouble validating Card1." );
    throw e;
  }
};
