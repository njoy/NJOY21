struct Des {
  using Value_t = std::string;
  static std::string name(){ return "des"; }
  static std::string description(){
    return
      "The des argument is a single quote deliminated string of 66\n"
      "characters or less (quotations excluded). This argument is used\n"
      "to describe MF=1/MT=451 on the new ENDF tape for the fixture.";
  }
  static bool verify( const Value_t& s ){ return s.length() <= 66; }
};
