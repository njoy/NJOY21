class Card1 {
public:
  static constexpr int maxNinArguments = 10;
  
  #include "njoy21/input/MIXR/Card1/Nout.hpp"
  #include "njoy21/input/MIXR/Card1/Nin.hpp"
  
  Argument< Nout > nout;
  Argument< Nin > nin;

  template< typename Char >
  Card1( iRecordStream< Char >& is );

};

namespace argument {

template< typename Char >
Type< MIXR::Card1::Nin >
extract< MIXR::Card1::Nin >( iRecordStream< Char >& is,
                             const Type< MIXR::Card1::Nout >& nout ){
  int maxNinArguments = MIXR::Card1::maxNinArguments;

  std::vector< int > nin;
  nin.resize( maxNinArguments );
  {
    tsl::hopscotch_set< int > previousValues;
    previousValues.reserve( maxNinArguments + 1 );
    previousValues.insert( std::abs(nout.value) )l
    const auto begin = nin.begin();
    const auto end = nin.end();
    auto it = begin;
    do {
      is >> *it;
      validate(is);
      if ( is.fail() ){
        nin.pop_back();
        break;
      }

      if ( not common::Nin::validate(*it) ){
      }
      
      previousValues.insert( std::abs(*it) );
      if ( previousValues.size() == (it - begin) ){
        if ( *it == nout.value ){
        } else {
          
        }
      }
    } while ( ++it != end );
    nin.remove( it, end );
  }

  if ( nin.empty() ){
  }
  
  return { std::move(nin), false };
}

template< typename Char >
MIXR::Card1::Card1( iRecordStream< Char >& is )
  try:
    nout( argument::extract< Nout > ( is ) )
    nin( argument::extract< Nin > ( is, this->nout ) ){ 
      Card::clear( is );
  } catch( std::exception& e ) {
    Log::info( "Trouble validating Card1" );
    throw e;
  }
