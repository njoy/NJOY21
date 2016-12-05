struct Cards {
  using Value_t = std::string;
  static std::string name(){ return "cards"; }

  static std::string description(){
    return
        "The cards argument is a single quote delimited string of 66 \n"
        "characters or less (quotations excluded). The argument is added as a\n"
        "description TEXT record in MF=1,MT451 of the PENDF file.";
  }

  static bool verify( const Value_t& s ){
    return s.length() < 67;
  }
};
