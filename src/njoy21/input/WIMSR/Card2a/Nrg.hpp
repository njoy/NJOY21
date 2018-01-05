struct Nrg {
  using Value_t = int;
  static std::string name(){ return "nrg"; }
  static std::string description(){
    return "The nrg parameter specifies the number of resonance groups in the\n"
           "user specified group structure.  For example, in the default\n"
           "69-group structure, there are 13 resonance groups.";
  }
  static bool verify( const Value_t nrg, const int ngnd ){
    return ( nrg > 0 and nrg <= ngnd );
  }
};
