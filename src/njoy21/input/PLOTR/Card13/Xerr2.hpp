struct Xerr2 {
  using Value_t = optional< double >;
  static std::string name(){ return "xerr2"; }
  static std::string description(){
    return
      "The xerr2 argument specifies the upper x error limit.\n"
      "Setting this value to zero results in the same value as xerr1.";
  }
  static Value_t defaultValue(){ return std::nullopt; }
  static bool verify( const Value_t v ){
    return ( *v >= 0.0 ) or ( v == std::nullopt );
  }
};
