struct Matd : public argument::common::Matd {
  using Value_t = argument::common::Matd::Value_t;
  static std::string name(){ return "matd"; }
  static std::string description(){
    return
      "The matd argument specifies the material to be processed.\n"
      "It is an integer corresponding to an ENDF material number\n"
      "and refers to a material number on the PENDF tape.";
  }

  static bool verify( const Value_t& m ){ return m >= 1 && m < 10000; }
};
