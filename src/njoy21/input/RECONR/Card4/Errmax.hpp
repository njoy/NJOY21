struct Errmax {
  using Value_t = double;
  static std::string name(){ return "errmax"; }

  static std::string description(){
    return
        "The errmax argument specifies the fractional reconstruction \n"
        "tolerance used when resonance-integral error criterion *is* \n"
        "satisifed.\n"
        "\n"
        "errmax must be >= to err. The default value is 10 times err.";
  }

  static Value_t defaultValue( const Argument< Err >& err ){ 
    return err.value*10; 
  }

  static bool verify( const Value_t& v, const Argument< Err >& err ){
    return v >= err.value;
  }
};
