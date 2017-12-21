struct Lambda {
  using Value_t = std::vector<double>;

  static std::string name(){ return "lambda"; }
  static std::string description(){
    return "The lambda parameter specifies the resonance-group goldstein\n"
           "lambdas.  It has 13 values for default 69-group structure,\n"
           "otherwise it has (Card2a:Nrg) values.";
  }
  static bool verify( const Value_t lambdaList, const int igroup,
                      const unsigned int nrg ){
    if( igroup == 0 and lambdaList.size() != 13 ) return false;
    if( lambdaList.size() != nrg ) return false;
    for( auto lambda : lambdaList ){
      if( lambda < 0.0 ) return false;
    }
    return true;
  }
};
