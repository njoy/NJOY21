struct Hmat{
  using Value_t = std::string;
  static std::string name(){ return "hmat"; }
  static std::string description(){
    return "The hmat paramter specifies the hollerith material identifier\n"
           "for each material.";
  }
  static bool verify( const Value_t hmat ){ return hmat.size() < 9; }
};
