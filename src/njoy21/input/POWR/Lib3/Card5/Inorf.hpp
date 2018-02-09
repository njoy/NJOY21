struct Inorf{
  using Value_t = int;
  static std::string name(){ return "inorf"; }
  static std::string description(){
    return "The inorf parameter specifies whether or not to include resonance\n"
           "fission if found.\n"
           " 0 = include resonance fission if found\n"
           " 1 = do not include resonance fission";
  }
  static bool verify( const Value_t inorf ){
    return ( inorf == 0 or inorf == 1 );
  }
};
