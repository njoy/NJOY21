struct Joutp{
  using Value_t = std::vector< int >;
  static std::string name(){ return "joutp"; }
  static std::string description(){
    return "The joutp parameter specifies the output particle id for each\n"
           "data type.";
  }
  static bool verify( const Value_t joutpList, const unsigned int ntype ){
    if( joutpList.size() != ntype ) return false;
    auto pos = std::find_if( joutpList.begin(), joutpList.end(),
                             []( const int joutp )->bool{ return joutp < 0; } );
    if( pos != joutpList.end() ) return false;
    return true;
  }
};
