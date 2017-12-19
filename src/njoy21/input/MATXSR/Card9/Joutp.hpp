struct Joutp{
  using Value_t = std::vector< int >;
  static std::string name(){ return "joutp"; }
  static std::string description(){
    return "The joutp parameter specifies the output particle id for each\n"
           "data type.";
  }
  static bool verify( const Value_t joutpList, const unsigned int ntype ){
    if( joutpList.size() != ntype ) return false;
    for( auto joutp : joutpList ){
      if( joutp < 0 ) return false;
    }
    return true;
  }
};
