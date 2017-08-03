struct Icolor {
  using Value_t = int;
  
  static std::string name(){ return "icolor"; }
  static std::string description(){ 
    return
      "The icolor input selects the color or monochrome style for the plot\n"
      "option. icolor can take a value of 0, 1, or 2. A value of 0 indicates\n"
      "that a monochrome scheme will be used (with cross hatching), while 1\n"
      "indicates that there will be a color background and contours. A value\n"
      "of 2 corresponds to color background and contours, but that a card2'\n"
      "will be provided for additional information.\n"
      "\n"
      "icolor has a default value of 0."; 
  } 
  
  static Value_t defaultValue( ){ return 0; }
  
  static bool verify( const Value_t icolor ){
    if( icolor == 0 or icolor == 1 or icolor == 2 ){ return true; }
    return false;
  }
};
