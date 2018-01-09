struct Mat{
  using Value_t = int;
  static std::string name(){ return "mat"; }
  static std::string description(){
    return "The mat parameter specifies the list of all desired endf\n"
           "materials.  For materials not found on the gendf tape, use\n"
           "ident for mat.  If mat is less than zero (0), add 100 to output\n"
           "ident (for second isomer of an isotope).";
  }
  static bool verify( const Value_t mat ){
    return true;
  }
};
