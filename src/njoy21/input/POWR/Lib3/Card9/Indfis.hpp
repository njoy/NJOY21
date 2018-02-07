struct Indfis{
  using Value_t = double;
  static std::string name(){ return "indfis"; }
  static std::string description(){
    return "The indfis parameter specifies the fission indicator for this\n"
           "time-dependent isotope.";
  }
};
