struct Mtb {
  using Value_t = int;
  static std::string name(){ return "mtb"; }
  static std::string description(){
    return "The mtb parameter specifies the reaction for the previously\n"
           "defined material that will be replaced by the material/MT\n"
           "specified later in this card.";
  }
  static bool verify( const Value_t mtb ){
    return ( std::abs( mtb ) < 1000 and mtb != 0 );
  }
};
