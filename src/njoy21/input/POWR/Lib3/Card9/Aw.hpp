struct Aw{
  using Value_t = double;
  static std::string name(){ return "aw"; }
  static std::string description(){
    return "The aw parameter specifies the atomic weight of this\n"
           "time-dependent isotope.";
  }
  static bool verify( const Value_t aw ){
    return aw > 0.0;
  }
}
