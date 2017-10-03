struct Xerr2 {
  using Value_t = double;
  static std::string name(){ return "xerr2"; }
  static std::string description(){
    return
      "The xerr2 argument specifies the upper x error limit.\n"
      "Setting this value to zero results in the same value as xerr1.";
  }
  static bool verify( Value_t v, Value_t xerr1 ){
    if( v == 0.0 ) this->value = xerr1;
    return ( v >= 0.0 );
  }
};
