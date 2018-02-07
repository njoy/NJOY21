struct Iclaps{
  using Value_t = int;

  static std::string name(){ return "iclaps"; }
  static std::string description(){
    return "The iclaps parameter specifies the group collapsing option.\n\n"
           " 0 = collapse from 185 group to desired group structure (default)\n"
           " 1 = no collapse";
  }
  static Value_t defaultValue(){ return 0; }
  static bool verify( const Value_t iclaps ){
    return ( iclaps == 0 or iclaps == 1 );
  }
};
