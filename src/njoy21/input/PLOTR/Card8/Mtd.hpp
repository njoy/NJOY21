struct Mtd : public GROUPR::Card9::Mtd {
  using Value_t = optional< GROUPR::Card9::Mtd::Value_t >;

  static std::string description(){
    return 
        GROUPR::Card9::Mtd::description() + "\n\n"
        "If the Iverf value is 0, this value is ignored.";
  }

  static Value_t defaultValue( const int iverf ){
    if( iverf == 0 ) return std::nullopt;
    return 0;
  }
  static bool verify( const Value_t M, const int iverf ){
    if( iverf == 0 ) return true;
    return GROUPR::Card9::Mtd::verify( *M );
  }
};
