struct Errmax {
  using Value_t = double;
  
  static std::string name(){ return "errmax"; }

  static std::string description(){
    return
      "errmax is an optional argument specifing the fractional tolerance for\n"
      "grid thinning used when integral criterion is satisfied. This value is\n"
      "required to be positive and greater than the errthn argument. When\n"
      "unspecified, this argument defaults to 10 times the errthn argument value\n"
      "\n"
      "See the description for errint for information regarding the integral\n"
      "criterion.";
  }
  
  static Value_t defaultValue( const Argument< Errthn >& errthn ){
    return 10 * errthn.value;
  }

  static Value_t verify( const Value_t& v, const Argument< Errthn >& errthn ){
    return v >= errthn.value;
  }
};
