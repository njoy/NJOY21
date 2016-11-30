struct Tapeid {
  using Value_t = std::string;
  static std::string name(){ return "tapeid"; }
  static std::string description(){
    return
      "The tapeid argument is a single quote delimited string of 66 characters\n"
      "or less (quotations excluded). This argument is used as the TPID record\n"
      "in File 1 of the output tape.";
  }
  static bool verify( const Value_t& s ){
    return s.length() < 67;
  }
};
