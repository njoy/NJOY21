struct Adens {
  using GperCC = decltype(Gram{} / pow( Centi<Meter>{}, Ratio<3> ));
  using Value_t = Quantity< GperCC >;

  static std::string name(){ return "adens"; }
  static std::string description(){
    return "The adens parameter specifies the density of the isotope in the\n"
           "mixture in g/cc.";
  }
  static bool verify( const Value_t adens ){
    return adens.value >= 0.0;
  }
};
