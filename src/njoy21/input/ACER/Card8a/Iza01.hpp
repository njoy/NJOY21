struct Iza01 {
  using Value_t = int;
  static std::string name(){ return "iza01"; }

  static std::string description(){
    return
        "The iza arguments specify the ZA value for the moderator components.";
  }

  static bool verify( const Value_t& M ){ return M > 0; }
};
