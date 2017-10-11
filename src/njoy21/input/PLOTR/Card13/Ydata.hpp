struct Ydata {
  using Value_t = double;
  static std::string name(){ return "ydata"; }
  static std::string description(){
    return
      "The ydata argument specifies the y-value for the data point.\n";
  }
  static bool verify( Value_t ){
    return true;
  }
};
