struct Comment {
  using Value_t = optional<std::string>;
  static std::string name(){ return "comment"; }
 

  static std::string description(){
    return
      "Comment is a comment";
  }
  
  static Value_t defaultValue() { return nullopt; }

  static bool verify( Value_t str ){ return str->length() <= 80; } 
};

