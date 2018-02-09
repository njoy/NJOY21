struct Sigpot {
  using Value_t = double;
  static std::string name(){ return "sigpot"; }
  static std::string description(){
    return "The sigpot parameter specifies the average effective potential\n"
           "scattering for the isotope.";
  }
  static bool verify( const Value_t sigpot ){
    return sigpot >= 0.0;
  }
};
