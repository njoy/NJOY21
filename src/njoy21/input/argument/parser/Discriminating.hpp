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
