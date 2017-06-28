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

  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t v ){
    return (std::abs(v) > 19 && std::abs(v) < 100);
  }
};
