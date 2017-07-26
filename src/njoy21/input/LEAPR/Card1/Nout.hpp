struct Nout : public argument::common::Nout {
  
  static bool verify( const Value_t v ){
    return argument::common::Nin::verify( v );
  }
};
