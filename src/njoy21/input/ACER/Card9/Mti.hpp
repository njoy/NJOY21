struct Mti {
  using Value_t = int;
  static std::string name(){ return "mti"; }

  static std::string description() {
    return
        "The mti argument must correspond to one of the values used as input\n"
        "for the THERMR module specifying the reacion nmber. This material \n"
        "must be in the PENDF tape as input in the npend argument.";
  }

  static bool verify( const Value_t& mti ){ 
    return ( mti > 0 ) and ( mti < 1000 ); 
  }
};
