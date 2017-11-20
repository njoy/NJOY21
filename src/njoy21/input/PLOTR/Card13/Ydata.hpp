struct Ydata {
  using Value_t = optional< double >;
  static std::string name(){ return "ydata"; }
  static std::string description(){
    return
      "The ydata argument specifies the y-value for the data point.\n";
  }
  static Value_t defaultValue(){ return std::nullopt; }
};
