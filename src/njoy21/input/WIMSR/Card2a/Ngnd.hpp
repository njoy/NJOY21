struct Ngnd {
  using Value_t = int;
  static std::string name(){ return "ngnd"; }
  static std::string description(){
    return "The ngnd parameter specifies the number of groups for the custom\n"
           "group structure being specified by the user.";
  }
  static Value_t defaultValue(){ return 69; }
  static bool verify( const Value_t ngnd ){
    return ngnd > 0;
  }
};
