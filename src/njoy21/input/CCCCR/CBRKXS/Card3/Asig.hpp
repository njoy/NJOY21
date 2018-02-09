struct Asig {
  using Value_t = std::vector< double >;
  static std::string name(){ return "asig"; }
  static std::string description(){
    return "The asig parameter specifies the desired sigpo values.";
  }
  static bool verify( const Value_t asig, const int ){
    for( auto s : asig ){
      if( s < 0.0 ) return false;
    }
    return true;
  }
};
