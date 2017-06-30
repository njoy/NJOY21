struct Hisnam {
  using Value_t = std::string;
  static std::string name(){ return "hisnam"; }

  static std::string description(){
    return
      "Hisnam is a 6-character isotope name. This material name will appear\n"
      "in the comment cards before tables and in the special labels added \n"
      "to the right-hand edge of each card. The material numbers are the\n"
      "same ENDF MAT numbers used when preparing the multigroup cross\n"
      "sections.";
  }
  
  static bool verify( Value_t str ){ return str.length() <= 6; } 
};

