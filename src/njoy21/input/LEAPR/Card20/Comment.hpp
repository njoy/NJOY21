struct Comment {
  using Value_t = optional<std::string>;
  static std::string name(){ return "comment"; }
 

  static std::string description(){
    return
      "The comment input gives the new comment cards that are to be added\n"
      "to the section MF=1/MT=451 on the output ENDF file.\n"
      "\n"
      "The comment cards are terminated by an empty card.";
  }
  
  static Value_t defaultValue() { return nullopt; }

  static bool verify( Value_t str ){ return str->length() <= 66; } 
};

