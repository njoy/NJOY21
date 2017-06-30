struct Nin : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;
  
  static bool verify( const Value_t v ){
    return argument::common::Nin::verify(v);
  }
};
