namespace argument{

#include "njoy21/input/argument/primitive.hpp"

template< bool >
struct defaultField{
  bool defaulted;
};

template<>
struct defaultField< false >{};

template
< typename Policy,
  bool defaults = primitive::HasDefault< Policy >::value,
  bool verifies = primitive::RequiresVerification< Policy >::value >
struct Type : public defaultField< defaults > {
  using Parent = primitive::Parent_t< Policy, defaults, verifies >;
  using Data_t = typename Policy::Value_t;
  Data_t value;
  template< typename Istream, typename... Args >
  static bool read( Istream& is, Data_t& d, Args&&... args ){
    return Parent::read( is, d, std::forward<Args>(args)... );
  }
};

#include "njoy21/input/argument/common.hpp"

template< typename Istream, typename Policy, typename... Args >
inline void read( Istream& is, Type< Policy, true >& argument, Args&&... args ){
  argument.defaulted =
    not Type< Policy >::read( is, argument.value, std::forward<Args>(args)... );
}

template< typename Istream, typename Policy, typename... Args >
inline void read( Istream& is, Type< Policy, false >& argument, Args&&... args ){
  Type< Policy >::read( is, argument.value, std::forward<Args>(args)... );
}

template< typename Char >
using iRecordStream =
  utility::stream::basic_RecordOrientedStream< std::basic_istream, Char >;

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

template< typename Policy, typename Char >
void domainError( iRecordStream< Char >& is ){
  echoLine( is, true );
  Log::info( "\n{}\n", Policy::description() );
}

template< typename Policy, typename Char, typename... Args >
inline auto extract
( iRecordStream< Char >& is, Args&&... args ){
  argument::Type< Policy > argument;
  try {
    read( is, argument, std::forward<Args>(args)... );
  } catch ( std::ios_base::failure& f ){
    Log::error( "Failed to read {} from input", Policy::name() );
    echoLine( is, false );
    throw f;
  } catch ( std::domain_error& de ){
    Log::error( "Encountered invalid value for {}", Policy::name() );
    domainError<Policy>( is );
    throw de;
  }
  return argument;
}

}

template< typename Policy >
using Argument = argument::Type< Policy >;
