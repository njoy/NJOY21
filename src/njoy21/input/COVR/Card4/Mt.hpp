struct Mt {
  using Value_t = int;
  static std::string name(){ return "mt"; }

  static std::string description(){
    return
      "If mt is positive, then a single covariance matrix for reaction\n"
      "(mat,mt) with reaction (mat1,mt1) will be read from nin and processed.\n"
      "If a negative value is provided, the mt with the positive value will\n"
      "be stripped ( i.e. - a value of -62 will strip mt=62 along with some\n"
      "others).";
  }
  static Value_t defaultValue(){ return 0; }
};

