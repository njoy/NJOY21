struct Istyle {
  using Value_t = int;
  static std::string name(){ return "istyle"; }
  static std::string description(){
    return
      "The istyle argument specifies the character style for the plot defined\n"
      "in the rest of the PLOTR input.\n\n"
      "There are two options: 1 for roman and 2 for swiss.\n"
      "The default value is 2 specifying the swiss character style.";
  }
  static int defaultValue(){ return 2; }
  static bool verify( Value_t v ){ return ( v == 1 or v == 2 ); }
};
