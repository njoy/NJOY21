struct Abs{
  using Value_t = std::vector< double >;
  static std::string name(){ return "abs"; }
  static std::string description(){
    return "The abs parameter specifies the absorption values.  There are\n"
           "69 values that can be entered.  The default values are all\n"
           "zeroes (0).";
  }
  static Value_t defaultValue(){ return std::vector<double>(69,0.0); }
};
