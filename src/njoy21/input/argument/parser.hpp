namespace parser {

#include "njoy21/input/argument/parser/src/validate.hpp"
#include "njoy21/input/argument/parser/FortranString.hpp"
#include "njoy21/input/argument/parser/src/rightShift.hpp"
#include "njoy21/input/argument/parser/src/read.hpp"

template< typename T >
struct Base {
  using Value_t =
    std::conditional_t< std::is_default_constructible<T>::value,
			T, std::optional<T> >;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Value_t& d, Args&&... args ){
    return parser::read( is, d, std::forward<Args>(args)... );
  }
};

template< typename Core >
struct Required : protected Core {
  using Value_t = typename Core::Value_t;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Value_t& d, Args&&... args ){
    Core::read( is, d, std::forward<Args>(args)... );
    if ( is.fail() ){
      is.eof() ? throw std::ios_base::failure("") : throw std::domain_error("");
    }
    return true;
  }
};

template< typename Core >
struct Optional : protected Core {
  using Value_t = typename Core::Value_t;
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Value_t& d , Args&&... args ){
    auto success = Core::read( is, d, std::forward<Args>(args)... );
    if ( not is.fail() ){ return success; }
    is.clear();
    return ( is.peek() == '/' ) ? false :
                                  throw std::domain_error("");
  }
};

template< typename Core, typename Policy = typename Core::Policy_t >
struct Discriminating : protected Core {
  using Policy_t = Policy;
  using Value_t = typename Core::Value_t;
  template< typename Arg >
  static std::enable_if_t
  < std::is_same< Arg, typename Policy::Value_t >::value, Arg& >
  unwrap( Arg& v ){ return v; }

  template< typename Arg >
  static std::enable_if_t
  < std::is_same< Arg, std::optional< typename Policy::Value_t > >::value,
    typename Policy::Value_t& > unwrap( Arg& v ){ return *v; }
  
  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Value_t& d, Args&&... args ){
    if ( Core::read( is, d, std::forward<Args>(args)... ) ){
      if ( not Policy::verify( unwrap(d), std::forward<Args>(args)... ) ){
	throw std::domain_error("");
      }
      return true;
    }
    return false;
  }
};

template< typename Core, typename Policy = typename Core::Policy_t >
struct Defaulted : protected Core {
  using Policy_t = Policy;
  using Value_t = typename Core::Value_t;

  template< typename Char, typename... Args >
  static bool read( iRecordStream<Char>& is, Value_t& d, Args&&... args ){
    if ( not Optional<Core>::read( is, d, std::forward<Args>(args)... ) ){
      d = Policy::defaultValue( std::forward<Args>(args)... );
      return false;
    }
    return true;
  }
};

template< typename Policy, bool, bool >
struct Composition;

template< typename Policy >
struct Composition< Policy, false, false >{
  using type = Required< Base< typename Policy::Value_t > >;
};

template< typename Policy >
struct Composition< Policy, false, true >{ 
  using type = Discriminating
               < Required< Base< typename Policy::Value_t > >, Policy >;
};

template< typename Policy >
struct Composition< Policy, true, false >{
  using type = Defaulted< Base< typename Policy::Value_t >, Policy >;
};

template< typename Policy >
struct Composition< Policy, true, true >{
  using type = 
    Defaulted
    < Discriminating
      < Optional
        < Base
	  < typename Policy::Value_t > >, Policy > >;
};

template< typename Policy,
	  bool defaults = argument::policy::hasDefault< Policy >,
	  bool verifies = argument::policy::requiresVerification<Policy> >
using Type = typename Composition< Policy, defaults, verifies >::type;

}
