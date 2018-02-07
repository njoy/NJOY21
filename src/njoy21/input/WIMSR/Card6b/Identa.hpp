struct Identa {
  using Value_t = int;

  static std::string name(){ return "identa"; }
  static std::string description(){
    return "The identa parameter specifies the identification of decay\n"
           "product isotope (zero if stable).";
  }
  static bool verify( const Value_t identa ){
    return identa >= 0 and identa < 10000;
  }
};
