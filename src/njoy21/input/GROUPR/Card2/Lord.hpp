struct Lord {
  using Value_t = int;
  static std::string name(){ return "lord"; }

  static std::string description(){
    return 
        "The lord argument specifies the maximum Legendre order used for \n"
        "scattering matrices.";
  }

  static bool verify( const Value_t l ){ return l >= 0 ; }
};
