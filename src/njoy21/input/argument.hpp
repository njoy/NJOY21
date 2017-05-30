namespace argument{

#include "njoy21/input/argument/policy.hpp"
#include "njoy21/input/argument/Type.hpp"
#include "njoy21/input/argument/parser.hpp"
#include "njoy21/input/argument/common.hpp"

template< typename Char >
void echoLine( iRecordStream< Char >& is, const bool backtrack ){
  is.clear();
  const auto index = is.buffer.size();
  const auto& line = is.buffer;
  is.ignore( std::numeric_limits< std::streamsize >::max(), '\n' );
  const auto begin = std::begin( line );
  const auto end = std::end( line );
  const auto position = backtrack ?
    std::find_if( std::make_reverse_iterator( std::next( begin, index ) ),
		  std::make_reverse_iterator( begin ), ::isspace ).base() :
    std::next( begin, index );
  
  utility::echoErroneousLine( begin, position, end, is.lineNumber );
}

template< typename Policy, typename Data >
std::enable_if_t
< std::is_same< typename Policy::Value_t, Data >::value, Type<Policy> >
construct( Data& data, bool success ){
  return Type<Policy>( std::move(data), success );
}

template< typename Policy, typename Data>
std::enable_if_t
< not std::is_same< typename Policy::Value_t, Data >::value, Type<Policy> >
construct( Data& data, bool success ){
  return Type<Policy>( std::move(*data), success );
}

template< typename Policy, typename Char, typename... Args >
auto extract( iRecordStream< Char >& is, Args&&... args ){
  using Parser = typename parser::Type< Policy >;
  typename Parser::Value_t value;
  try {
    bool success = not Parser::read( is, value, std::forward<Args>(args)... );
    return construct< Policy >( value, success );
  } catch ( std::ios_base::failure& f ){
    Log::error( "Failed to read {} from input", Policy::name() );
    echoLine( is, false );
    throw f;
  } catch ( std::domain_error& de ){
    Log::error( "Encountered invalid value for {}", Policy::name() );
    echoLine( is, true );
    Log::info( "\n{}\n", Policy::description() );
    throw de;
  }
}

template< typename Policy, typename Char >
void domainError( iRecordStream< Char >& is ){
  echoLine( is, true );
  Log::info( "\n{}\n", Policy::description() );
}

}

template< typename Policy >
using Argument = argument::Type< Policy >;
