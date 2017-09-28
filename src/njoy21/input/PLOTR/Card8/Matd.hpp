struct Matd : public argument::common::Matd {
  using Value_t = argument::common::Matd::Value_t;
  static std::string description(){
    return
      argument::common::Matd::description() + "\n\n"
      "If the Iverf value is 0, this value is ignored.";
  }

  static bool verify( const Value_t& i, const int iverf ){
    if( iverf == 0 ) return true;
    return argument::common::Matd::verify( i );
  }
};
