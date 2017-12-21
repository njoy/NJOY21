struct Rbot {
  using Value_t = optional< double >;
  static std::string name(){ return "rbot"; }
  static std::string description(){
    return
      "The rbot argument specifies the lower bound for the alternate y-axis\n"
      "or the z-axis.";
  }
  static Value_t defaultValue(){
    return std::nullopt;
  }
};
