struct Iopp {
  using Value_t = int;
  static std::string name(){ return "iopp"; }

  static std::string description(){
    return 
        "The iopp flag determines whether the 'newer' detailed photon data\n"
        "is used, or to generate the older, 30x20 photon production matrices.\n"
        "\n"
        "If the 30x20 matrices are chosen (iopt=0), then GROUPR must be run\n"
        "before ACER to generate multi-group versions of the photon \n"
        "production matrices for all reactions, and the resulting GENDF tape\n"
        "must be coupled to ACER using the ngend input parameter in Card 1.\n"
        "\n"
        "The default (and preferred) is to use the detailed photon data.";
  }

  static Value_t defaultValue(){ return 1; }

  static bool verify( const Value_t& I ){ 
    // This assumes that the ngend value has already been verified
    return ( I == 0 or I == 1 );
  }
};
