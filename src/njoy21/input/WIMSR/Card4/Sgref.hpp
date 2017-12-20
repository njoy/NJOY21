struct Sgref {
  using Value_t = double;
  static std::string name(){ return "sgref"; }
  static std::string description(){
    return "The sgref parameter specifies the reference sigma-zero value.\n"
           "It is used for the elastic cross section and matrix, because\n"
           "these quantities are not normally self-shielded by WIMS.\n"
           "Normally, 1e10 is appropriate, but for the major fissionable\n"
           "material in the reactor (i.e., U-238 or Th-232), it may be\n"
           "better to use a realistic number like sgref=50.\n\n"
           "For sgref >= 1E+10 - to select all cross sections at infinite\n"
           "                     dilution but fully shielded elastic cross\n"
           "                     section.\n"
           "For sgref <  1E+10 - to select all cross sections at infinite\n"
           "                     dilution.\n"
           "For sgref == sig0  - Takes sig0 for the list on GROUPR input\n"
           "                     to select all cross sections at that sig0.";
  }
  static bool verify( const Value_t sgref ){
    return sgref >= 0;
  }
};
