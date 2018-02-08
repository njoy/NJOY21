class Card3 {
public:

using Mt = argument::common::Matd;

Argument< Mt > mt;

template< typename Istream >
Card3( Istream& is )
try:
  mt( is )
{
  Card::clear( is );
}
catch( std::exception& e ){
  Log::info( "Trouble reading Card3." );
  throw e;
}
};
