struct Yield{
  using Value_t = double;
  static std::string name(){ return "yield"; }
  static std::string description(){
    return "The yield parameter specifies the yields of this isotope from\n"
           "each of the fissionable isotopes.";
  }
  static Value_t defaultValue( const int nfis2 ){
    return std::vector< double >( nfis2, 0.0 );
  }
  static bool verify( const Value_t yields, const int ){
    for( auto yield : yields ){
      if( yield < 0.0 ) return false;
    }
    return true;
  }
};
