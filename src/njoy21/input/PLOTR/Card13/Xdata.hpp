struct Xdata {
  using Value_t = double;
  static std::string name(){ return "xdata"; }
  static std::string description(){
    return
      "The xdata argument specifies the x-value for the data point.\n";
  }
  static bool verify( Value_t ){
    return true;
  }
};
