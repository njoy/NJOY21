struct Nsblok {
  using Value_t = int;
  static std::string name(){ return "nsblok"; }
  static std::string description(){
    return "The nsblok parameter specifies the subblocking option for the\n"
           "scattering matrix.  The options are 1 or ngrup sub-blocks.";
  }
  static bool verify( const Value_t nsblok ){
    return ( nsblok == 1 or nsblok == ngroup );
  }
};
