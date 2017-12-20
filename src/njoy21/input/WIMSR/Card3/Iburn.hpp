struct Iburn{
  using Value_t = int;
  static std::string name(){ return "iburn"; }
  static std::string description(){
    return "The iburn parameter specifies whether the burnup data is included\n"
           "in the input.\n\n"
           "The values and their meanings are:\n"
           " -1 = suppress printout of burnup data\n"
           "  0 = no burnup data is provided (default) \n"
           "  1 = burnup data is provided in cards 5 and 6\n";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t iburn ){
    return ( iburn == -1 or iburn == 0 or iburn == 1 );
  }
};
