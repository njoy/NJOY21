struct Mt1 {
  using Value_t = int;
  static std::string name(){ return "mt1"; }
  static std::string description(){
    return "The mt1 parameter specifies the reaction for the material/MT\n"
           "combination to be added to the covariance reaction list.";
  }
  static bool verify( const Value_t mt1 ){
    return ( mt1 > 0 and mt1 < 1000 );
  }
};
