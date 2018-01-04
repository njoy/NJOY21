struct Yerr1 {
  using Value_t = optional< double >;
  static std::string name(){ return "yerr1"; }
  static std::string description(){
    return
      "The yerr1 argument specifies the lower y error limit.\n"
      "Setting this value to zero results in no error bars in the y-direction.";
  }
  static Value_t defaultValue(){ return std::nullopt; }
  static bool verify( const Value_t v ){
    return v >= 0.0;
  }
};
