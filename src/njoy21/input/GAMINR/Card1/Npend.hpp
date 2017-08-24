struct Npend : public argument::common::Npend {
  using Value_t = argument::common::Npend::Value_t;

  static std::string description(){
    return "FOObarBAZ";
  }
  static std::string name(){
    return "Npend";
  }

//  static bool verify( const Value_t v, const Argument<Nendf>& nendf ){
//    return ( ( std::abs(v) > 19 ) and ( std::abs(v) < 100 ) 
//         and ( std::abs(v) != std::abs(nendf.value) ) );
//  }
};
