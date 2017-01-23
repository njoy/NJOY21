struct Npk {
  using Value_t = int;
  static std::string name(){ return "npk"; }
  static std::string description(){
    return
      "npk is a optional integer argument specifying the number of partial\n"
      "KERMAs desired. As such, the npk value is required to be non-negative.\n"
      "Note that this argument need not consider the total KERMA, which is always\n"
      "computed by HEATR. When unspecified, this argument defaults to zero.\n";
  }

  static Value_t defaultValue(){ return 0; }

  static bool verify( const Value_t& i ){ return (i > -1); }
};
