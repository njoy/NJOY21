struct Hlibid {
  using Value_t = std::string;
  static std::string name(){ return "hlibid"; }
 

  static std::string description(){
    return
      "hlibid is an input string, normally containing the name of the\n"
      "output covariance library. It is written on the header records \n"
      "present at the beginning of each output data block.\n"
      "\n"
      "The hlibid input can have up to 6 characters.";
  }

  static bool verify( Value_t str ){ return str.length() <= 6; } 
};

