struct Nfg {
  using Value_t = int;
  static std::string name(){ return "nfg"; }
  static std::string description(){
    return "The nfg parameter specifies the number of fast groups in the\n"
           "user specified group structure.  For example, in the default\n"
           "69-group structure, there are 14 fast groups.";
  }
  static bool verify( const Value_t nfg, const int ngnd ){
    return ( nfg > 0 and nfg <= ngnd );
  }
};
