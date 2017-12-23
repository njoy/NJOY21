struct Nfid {
  using Value_t = int;
  static std::string name(){ return "nfid"; }
  static std::string description(){
    return "The nfid parameter is unused.\n"
           "That said, the nfid parameter is the identification number for\n"
           "the material used on the output WIMS library.";
  }
  static Value_t defaultValue(){ return 0; }
};
