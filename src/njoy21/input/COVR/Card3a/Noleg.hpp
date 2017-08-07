struct Noleg {
  using Value_t = int;
  
  static std::string name(){ return "noleg"; }
  static std::string description(){ 
    return
      "The noleg input indicates the plot legend option, where 'Legend' here\n"
      "refers to the gray-shading scale (key) as well as the figure caption.\n"
      "A noleg = 1 option is used as a rough-draft mode to display plots\n"
      "quickly, without any legends. A value of 0 is used to display a legend\n"
      "for all plots, and a value of -1 is used to display a legend for only\n"
      "the first subcase only.\n"
      "\n"
      "noleg has a default value of 0.";
  } 
  
  static Value_t defaultValue( ){ return 0; }
  
  static bool verify( const Value_t n ){ return n == 0 or n == 1 or n == -1; }
};
