struct Nform {
  using Value_t = int;
  static std::string name(){ return "nform"; }
  static std::string description(){
    return
      "The nform argument specifies the format code for the input data.\n"
      "Setting nform to 0 indicates a free format input with optional\n"
      "error bars for x and y.";
  }
  static bool verify( Value_t v ){ return ( v >= 0 ); }
};
