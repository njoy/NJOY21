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
