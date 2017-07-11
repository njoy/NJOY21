struct Hisnam {
  using Value_t = optional<std::string>;
  static std::string name(){ return "hisnam"; }
 

  static std::string description(){
    return
      "Hisnam is a 6-character isotope name. This material name will appear\n"
      "in the comment cards before tables and in the special labels added \n"
      "to the right-hand edge of each card.";
  }
  
  static Value_t defaultValue() { return nullopt; }

  static bool verify( Value_t str ){ return str->length() <= 6; } 
};

