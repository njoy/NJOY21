struct Xerr1 {
  using Value_t = optional< double >;
  static std::string name(){ return "xerr1"; }
  static std::string description(){
    return
      "The xerr1 argument specifies the lower x error limit.\n"
      "Setting this value to zero results in no error bars in the x-direction.";
  }
  static Value_t defaultValue(){ return std::nullopt; }
  static bool verify( Value_t v ){
    return ( v >= 0.0 );
  }
};
