struct Nmat {
  using Value_t = unsigned int;
  static std::string name(){ return "nmat"; }
  static std::string description(){
    return "The number of materials. The maximum number allowed is 20.";
  }
// Value is based on resxsr.f90: 200-201 and 246-248
  static bool verify( const Value_t nm ){
    return nm < 21;
  }
};
