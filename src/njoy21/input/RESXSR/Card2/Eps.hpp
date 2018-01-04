struct Eps {
  using Value_t = double;
  static std::string name(){ return "eps"; }
  static std::string description(){
    return "Thinning tolerance.";
  }
  static bool verify( const Value_t eps ){
    return eps > 0.0;
  }
};
