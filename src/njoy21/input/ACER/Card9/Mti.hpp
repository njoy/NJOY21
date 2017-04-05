struct Mti {
  using Value_t = int;
  static std::string name(){ return "mti"; }

  static std::string description() {
    return
        "The mti argument must corespond to one of the values used as input\n"
        "for the THERMR module. This material must be in the PENDF tape as\n"
        "input in the npend argument.";
  }

  static bool verify( const Value_t& mti ){ return mti > 0; }
};
