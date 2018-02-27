struct Ngn {
  using Value_t = int;
  static std::string name(){ return "ngn"; }
  static std::string description(){
    return "The ngn parameter specifies the number of groups if the ign value\n"
           "is set to 1 or 19, requiring a user-specified group structure.";
  }
  static bool verify( const Value_t ngn ){
    return ngn > 0;
  }
};
