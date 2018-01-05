struct Rdfid{
  using Value_t = double;
  static std::string name(){ return "rdfid"; }
  static std::string description(){
    return "The rdfid parameter is the identification number for the\n"
           "resonance data in the output of the WIMS library.";
  }
  static bool verify( Value_t rdfid, const int mat ){
    return rdfid == double(mat);
  }
};
