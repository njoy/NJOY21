struct Rstep {
  using Value_t = double;
  static std::string name(){ return "rstep"; }
  static std::string description(){
    return
      "The rstep argument specifies the spacing for tics on the alternate\n"
      "y-axis or the z-axis.\n\n"
      "The default behavior is automatic scaling.  The value is ignored if\n"
      "log scaling is used.";
  }
  static Value_t defaultValue(){ return 1.0; }
  static bool verify( Value_t v ){
    return ( v > 0 );
  }
};
