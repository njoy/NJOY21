struct Lori {
  using Value_t = int;
  static std::string name(){ return "lori"; }
  static std::string description(){
    return
      "The lori argument specifies the page orientation for the plot defined\n"
      "in the rest of the PLOTR input.\n\n"
      "There are two options: 0 for portrait and 1 for landscape.\n"
      "The size for portrait is 7.5in wide x 10in tall.\n"
      "The size for landscape is 10in wide x 7.5in tall.\n\n"
      "The default value is 1 specifying the landscape orientation.";
  }
  static int defaultValue(){ return 1; }
  static bool verify( Value_t v ){ return ( v == 0 or v == 1 ); }
};
