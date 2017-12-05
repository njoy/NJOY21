struct Igroup {
  using Value_t = int;
  static std::string name(){ return "igroup"; }
  static std::string description(){
    return "The igroup parameter specifies the group structure targeted for\n"
           "the WIMS transport code.\n"
           "The default value is 0, indicating the usual 69-group structure.\n"
           "A value of 9 specifies that the user will provide a custom group\n"
           "structure on Card2a.";
  }
  static Value_t defaultValue(){ return 0; }
  static bool defaultValue( const Value_t igroup ){
    return igroup == 0 or igroup == 9;
  }
};
