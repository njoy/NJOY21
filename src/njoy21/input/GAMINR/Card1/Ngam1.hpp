struct Ngam1{
  using Value_t = int;

  static std::string description(){
    return "FOObarBAZ";
  }
  static std::string name(){
    return "Ngam1";
  }

  static int defaultValue( const Argument< Nendf >&,
                           const Argument< Npend >&){ return 0; }
  static bool verify( const Value_t v,
                      const Argument< Nendf >& nendf,
                      const Argument< Npend >& npend){
    return (v == 0) or (
             ( argument::common::Nout::verify(v, nendf) ) and
             ( std::abs( npend.value ) != std::abs( v ) ) );
  }
};
