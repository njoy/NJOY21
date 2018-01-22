struct Identa {
  using Value_t = int;

  static std::string name(){ return "identa"; }
  static std::string description(){
    return "The identa parameter specifies the identification of capture\n"
           "product isotope.";
  }
  static bool verify( const Value_t identa ){
    return identa > 0 and identa < 10000;
  }
};
