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
