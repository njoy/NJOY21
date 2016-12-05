struct Errthn {
  using Value_t = double;
  static std::string name(){ return "errthn"; }

  static std::string description(){
    return 
      "The errthn argument specifies the fractional tolerance for grid\n"
      "thinning used when integral criterion is not satisfied. This value is\n"
      "required to be positive."
      "\n"
      "See the description for errint for information regarding the integral\n"
      "criterion.";
  }

  static bool verify( const Value_t& e ){ return (e > 0.0); }
};
