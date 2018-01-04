struct Matno{
  using Value_t = int;
  static std::string name(){ return "matno"; }
  static std::string description(){
    return "The matno parameter specifies the integer material identifier\n"
           "(endf mat number) for each material.";
  }
  static bool verify( const Value_t matno ){
    return ( matno > 0 and matno < 10000 );
  }
};
