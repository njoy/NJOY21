struct Ntis {
  using Value_t = int;
  static std::string name(){ return "ntis"; }
  static std::string description(){
    return "The ntis parameter specifies the number of time-dependent\n"
           "isotopes.\n"
           "For burnable materials, ntis = 2.\n"
           "For fissile materials ntis > 2 when fission product yields are\n"
           "given.\n"
           "The maximum allowable value is 100 (per wimsr.f90:244).";
  }
  static bool verify( const Value_t ntis ){
    return ntis > 0 and ntis < 101;
  }
};
