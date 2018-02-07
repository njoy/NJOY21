struct Ia{
  using Value_t = int;
  static std::string name(){ return "ia"; }
  static std::string description(){
    return "The ia parameter specifies the energy group.  If the value is\n"
           "zero (0), then there is no scattering from this group.";
  }
  static bool verify( const Value_t ia ){
    return ia >= 0;
  }
};
