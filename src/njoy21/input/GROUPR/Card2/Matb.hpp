struct Matb : public argument::common::Matd {
  using Value_t = argument::common::Matd::Value_t;
  static std::string name(){ return "matb"; }
  static std::string description(){
    return
      "The matb argument is an integer corresponding to an ENDF material\n"
      "identification number (often referred to as a MAT number) and refers\n"
      "to the material on the PENDF tape.\n"
      "\n"
      "If ngout=0 (from Card1), a negative value of matb is an option to \n"
      "automatically process all the materials on the ENDF input tape \n"
      "(nendf). If ngout !=0, then a negative value of matb is the option to\n"
      "add and/or replace MTs on ngout2 (from Card1).";
  }
  
  static bool verify( Value_t m ){ return m != 0; }
};
