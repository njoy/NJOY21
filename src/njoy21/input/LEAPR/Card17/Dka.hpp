struct Dka {
  using Value_t = decltype( pow( 1.0 * angstrom, Ratio<-1> ) );
  static std::string name(){ return "dka"; }
  static std::string description() {
    return
      "dka specifies the increment used to space the kappa values provided in\n"
      "the card18 skappa input. The dka input should be in units of inverse\n"
      "angstroms, and must be greater than zero.";
  }
  
  static bool verify( const Value_t& dka ){ 
//    return dka > 0.0 * std::declval<Value_t>( ); 
    return dka > 0.0 * pow( 1.0 * angstrom, Ratio<-1> );
  }
};
