struct Yerr2 {
  using Value_t = optional< double >;
  static std::string name(){ return "yerr2"; }
  static std::string description(){
    return
      "The yerr2 argument specifies the upper y error limit.\n"
      "Setting this value to zero results in the same value as yerr1.";
  }
  static Value_t defaultValue(){ return std::nullopt; }
  static bool verify( const Value_t v ){
    return ( *v >= 0.0 ) or ( v == std::nullopt );
  }
};
