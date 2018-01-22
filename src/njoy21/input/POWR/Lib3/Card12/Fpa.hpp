struct Fpa{
  using Value_t = std::vector< double >;
  static std::string name(){ return "fpa"; }
  static std::string description(){
    return "The fpa parameter specifies the absorption values for this\n"
           "isotope.";
  }
  static Value_t defaultValue(const int ngnd){
    return std::vector<double>(ngnd, 0.0);
  }
};
