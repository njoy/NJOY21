struct Mat {
  using Value_t = int;
  static std::string name(){ return "mat"; }
  
  static std::string description(){
    return
      "The mat argument is an integer corresponding to an ENDF material\n"
      "identification number (often referred to as a MAT number).\n"
      "\n"
      "MAT number correspondence varies widely between ENDF format revisions.\n"
      "as a result, verification is minimal; the input value is required to be\n"
      "greater than or equal to zero and less than 10000.";
  }

  static bool verify( const Value_t& i ){ return (i >= 0) and (i < 10000); }
};
