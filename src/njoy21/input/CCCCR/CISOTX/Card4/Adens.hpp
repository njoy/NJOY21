struct Adens {
  using Value_t = 1000 * Quantity< Gram > / Quantity< Meter > /
                         Quantity< Meter > / Quantity< Meter >;
  static std::string name(){ return "adens"; }
  static std::string description(){
    return "The adens parameter specifies the density of the isotope in the\n"
           "mixture in g/cc.";
  }
  static bool verify( const Value_t adens ){
    return adens >= 0.0 * grams / meter / meter / meter;
  }
};