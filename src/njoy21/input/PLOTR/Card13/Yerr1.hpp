struct Yerr1 {
  using Value_t = float;
  static std::string name(){ return "yerr1"; }
  static std::string description(){
    return
      "The yerr1 argument specifies the lower y error limit.\n"
      "Setting this value to zero results in no error bars in the y-direction.";
  }
  static bool verify( Value_t v ){
    return ( v >= 0.0 );
  }
};
