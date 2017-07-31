struct Aws {
  using Value_t = double;
  static std::string name(){ return "aws"; }
  static std::string description(){
    return
      "The aws input is the weight ratio of the secondary scatterer to\n"
      "neutron. aws is unitless, and must be positive.";
  }
  static bool verify( const Value_t& aws ){ return aws > 0.0; }
};
