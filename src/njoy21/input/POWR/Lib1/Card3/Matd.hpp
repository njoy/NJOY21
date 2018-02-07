struct Matd{
  using Value_t = int;

  static std::string name(){ return "matd"; }
  static std::string description(){
    return "The matd parameter specifies the material to be processed.\n"
           "The allowable values are between -9999 and 9999, inclusively.\n\n"
           "If the matd value is less than zero (0), only the absorption\n"
           "data will be read in with the material being the absolute\n"
           "value of this entry. The data will be read in directly from the\n"
           "input deck (see card 6).";
  }
  static bool verify( const Value_t matd ){
    return std::abs( matd ) < 10000;
  }
};
