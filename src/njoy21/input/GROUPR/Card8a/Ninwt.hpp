struct Ninwt : public argument::common::Nout {
  using Value_t = argument::common::Nout::Value_t;
  static std::string name(){ return "ninwt"; }

  static std::string description(){
    return 
        "The ninwt argument is the tape unit for new flux parameters. A\n"
        "non-zero value (and a non-zero value for argument jsigz) will cause \n"
        "the computed flux for a given fissionable to be written out onto \n"
        "this tape.\n"
        "\n"
        "The default value is 0.";
  }

  static Value_t defaultValue( 
                      const Argument< Card1::Nendf >&,
                      const Argument< Card1::Npend >&,
                      const Argument< Card1::Ngout1 >&,
                      const Argument< Card1::Ngout2 >&){
    return 0; 
  }

  static bool verify( const Value_t v,
                      const Argument< Card1::Nendf >& nendf,
                      const Argument< Card1::Npend >& npend,
                      const Argument< Card1::Ngout1 >& ngout1,
                      const Argument< Card1::Ngout2 >& ngout2 ){
    return ( argument::common::Nin::verify( v ) ) and
           ( std::abs( nendf.value ) != std::abs( v ) ) and
           ( std::abs( npend.value ) != std::abs( v ) ) and
           ( std::abs( ngout1.value ) != std::abs( v ) ) and
           ( std::abs( ngout2.value ) != std::abs( v ) );
  }
};
