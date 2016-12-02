struct Mat1 : public Card2::Mat1 {
  using Value_t = Card2::Mat1::Value_t;
  using Card2::Mat1::name;
  static std::string description(){
    return
      "The mat1 argument is an integer corresponding to an ENDF material\n"
      "identification number (often referred to as a MAT number) and \n"
      "specifies an additional material on the PENDF tape (specified by the\n"
      "card1 nin argument) to be broadened and thinned (in addition to the\n"
      "material specified by the BROADR card 2 mat1 argument)."
      "\n"
      "MAT number correspondence varies widely between ENDF format revisions.\n"
      "as a result, verification is minimal; the input value is required to be\n"
      "between zero and 9999, inclusively. Zero doesn't correspond to an actual\n"
      "ENDF material. Rather it specifies that there are no additional Card 5\n"
      "entries to process in a particular BROADR invocation";
  }
  
  static bool verify( const Value_t& v ){
    return ( not v ) or Card2::Mat1::verify( v );
  }
};
