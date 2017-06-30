struct Jsigz {
  using Value_t = int;
  
  static std::string name(){ return "jsigz"; }
  static std::string description(){
    return
      "The jsigz argument is the index number of sigma-zero desired. In\n"
      "other words, the user can use DTFR to specify that a given set of \n"
      "tables be prepared using a particular temperature (dtemp) and a\n"
      "particular background cross section (the jsigz-th value in set).";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t& i ){ return i > 0; }

};
