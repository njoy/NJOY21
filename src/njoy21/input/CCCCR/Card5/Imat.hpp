struct Imat{
  using Value_t = int;
  static std::string name(){ return "imat"; }
  static std::string description(){
    return "The imat parameter specifies the numerical isotope identifier\n"
           "using the ENDF material number.";
  }
  static bool verify( const Value_t imat ){
    return imat > 0;
  }
};
