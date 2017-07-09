struct Newfor {
  using Value_t = int;
  static std::string name(){ return "newfor"; }

  static std::string description(){
    return 
        "The newfor argument specifies whether the 'new' cumulative angle \n"
        "distributions, LAW=61, and outgoing particle distributions are to be\n"
        "used.\n"
        "\n"
        "This was introduced for MCNP4C and is suitable for all subsequent\n"
        "versions.";
  }

  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t& N ){ return ( N == 0 )  or ( N == 1 ); }
};
