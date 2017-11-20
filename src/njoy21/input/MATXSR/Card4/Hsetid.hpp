struct Hsetid{
  using Value_t = std::string;
  static std::string name(){ return "hsetid"; }
  static std::string description(){
    return "The hsetid parameter specifies the hollerith identification of\n"
           "the set.  It must be delimited by single quotes (') and ended\n"
           "by a forward slash (/).";
  }
  static bool verify( const Value_t hsetid ){ return hsetid.size() < 73; }
};
