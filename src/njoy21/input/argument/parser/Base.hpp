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
