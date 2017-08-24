struct Ngam2{
  using Value_t = int;

  static std::string description(){
    return "FOObarBAZ";
  }
  static std::string name(){
    return "Ngam2";
  }

  static int defaultValue( const Argument< Nendf >&,
                           const Argument< Npend >&,
                           const Argument< Ngam1 >&){ return 0; }
  static bool verify( const Value_t v,
                      const Argument< Nendf >& nendf,
                      const Argument< Npend >& npend,
                      const Argument< Ngam1 >& ngam1){
    return (v == 0) or (
             ( argument::common::Nout::verify(v, nendf)) and
             ( std::abs( npend.value ) != std::abs( v ) ) and
             ( std::abs( ngam1.value ) != std::abs( v ) ) and
             ( v*nendf.value > 0 ) and
             ( v*ngam1.value > 0 ) );
  }
};
