struct Amass {
  using Value_t = double;
  static std::string name(){ return "amass"; }
  static std::string description(){
    return "The amass parameter specifies the isotope atomic weight in grams.";
  }
  static bool verify( const Value_t amass ){
    return amass > 0.0;
  }
};
