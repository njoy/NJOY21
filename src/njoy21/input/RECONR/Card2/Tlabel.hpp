struct Tlabel {
  using Value_t = std::string;
  static std::string name(){ return "tlabel"; }

  static std::string description(){
    return
      "The tlabel argument is a single quote delimited string of 66 \n"
      "characters or less (quotations excluded). This argument is used as the\n"
      "TPID record in File 1 of the PENDF tape.";
  }

  static bool verify( const Value_t& s ){ return s.length() < 67; }
};
