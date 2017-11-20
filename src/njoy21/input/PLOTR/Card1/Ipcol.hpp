struct Ipcol {
  using Value_t = int;
  static std::string name(){ return "ipcol"; }
  static std::string description(){
    return
      "The ipcol argument specifies the page color for the plot defined\n"
      "in the rest of the PLOTR input.\n\n"
      "There are 8 options for the page color:\n"
      "    0 - white\n"
      "    1 - navajo white\n"
      "    2 - blanched almond\n"
      "    3 - antique white\n"
      "    4 - very pale yellow\n"
      "    5 - very pale rose\n"
      "    6 - very pale green\n"
      "    7 - very pale blue\n"
      "    The default value is 0 specifying the page color as white.";
  }
  static int defaultValue(){ return 0; }
  static bool verify( Value_t v ){ return ( v >= 0 and v < 8 ); }
};
