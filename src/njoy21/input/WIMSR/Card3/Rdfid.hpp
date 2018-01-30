struct Rdfid{
  using Value_t = double;
  static std::string name(){ return "rdfid"; }
  static std::string description(){
    return "The rdfid parameter is the identification number for the\n"
           "resonance data in the output of the WIMS library.";
  }
  static bool verify( const Value_t rdfid ){
    return ( rdfid > 0.0 and rdfid < 10000.0 );
  }
};
