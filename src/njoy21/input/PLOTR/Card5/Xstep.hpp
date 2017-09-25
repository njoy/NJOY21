struct Xstep {
  using Value_t = float;
  static std::string name(){ return "xstep"; }
  static std::string description(){
    return
      "The xstep argument specifies the spacing for tics on the energy (x)\n"
      "axis.\n\n"
      "The default behavior is automatic scaling.  The value is ignored if\n"
      "log scaling is used.";
  }
  static Value_t defaultValue(){ return 1.0; }
  static bool verify( Value_t v ){
    return ( v >= 0 );
  }
};
