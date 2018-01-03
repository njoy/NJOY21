struct Lambda {
  using Value_t = std::vector<double>;
  static std::string name(){ return "lambda"; }

  static std::string description(){
    return "The lambda parameter specifies the resonance-group goldstein\n"
           "lambdas.  It has 13 values for default 69-group structure,\n"
           "otherwise it has (Card2a:Nrg) values.";
  }
  static bool verify( const Value_t& lambdaList, const unsigned int nrg,
                      const int igroup ){
    if( igroup == 0 and lambdaList.size() != 13 ){
      Log::info( "List of resonance-group goldstein lambdas should have" );
      Log::info( "13 values when using the default 69-group structure." );
      Log::info( "Current list contains {} values.", lambdaList.size() );
      return false;
    }
    if( lambdaList.size() != nrg ){
      Log::info( "List of resonance-group goldstein lambdas should have" );
      Log::info( "Card2a::Nrg ({}) values when not using the", nrg );
      Log::info( "default 69-group structure.  Current list contains" );
      Log::info( "{} values.", lambdaList.size() );
      return false;
    }
    for( auto lambda : lambdaList ){
      if( lambda < 0.0 ){
        Log::info( "List of resonance-group goldstein lambdas value" );
        Log::info( "({}) is not allowed because it is negative.", lambda );
        return false;
      }
    }
    return true;
  }
};
