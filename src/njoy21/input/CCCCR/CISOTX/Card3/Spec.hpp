struct Spec {
  using Value_t = std::vector< std::vector< double > >;
  static std::string name(){ return "spec"; }
  static std::string description(){
    return "The spec parameter specifies the ngroup values of spec(i)=k,\n"
           "which define the range of groups i to be averaged to obtain\n"
           "spectrum k.  The index k ranges from 1 to ichix.  The model\n"
           "flux is used to weight each group i.";
  }
  static bool verify( const Value_t spec, const int, const int ){
    for( auto i : spec ){
      for( auto j : i ){
        if( j < 0.0 ) return false;
      }
    }
    return true;
  }
};
