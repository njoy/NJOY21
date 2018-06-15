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
