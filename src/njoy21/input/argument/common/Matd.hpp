struct Matd {
  using Value_t = int;
  static std::string name(){ return "matd"; }
  static std::string description(){
    return
      "The matd argument is an integer corresponding to an ENDF material\n"
      "identification number (often referred to as a MAT number).\n"
      "\n"
      "MAT number correspondence varies widely between ENDF format revisions.\n"
      "as a result, verification is minimal; the input value is required to be\n"
      "a positive value and less than 10000.";
  }

  static bool verify( const Value_t& i ){ return i > 0; }
};
