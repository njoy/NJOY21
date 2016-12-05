struct Errint {
  using Value_t = Quantity< Barn >;
  
  static std::string name(){ return "errint"; }

  static std::string description(){
    return
      "errint is an optional argument specifing the absolute integral error\n"
      "(tolerance in barns) for grid thinning operations. This value is required\n"
      "to be positive. When unspecified, this argument defaults to a value equal\n"
      "to one barn multiplied by the fractional tolerance divides by 20,000.";
  }
  
  static Value_t defaultValue( const Argument< Errthn >& errthn ){
    return 1.0 * barn * ( errthn.value / 2.0E4 );
  }

  static bool verify( const Value_t& v, const Argument< Errthn >& ){
    return v > 0.0 * barns;
  }
};
