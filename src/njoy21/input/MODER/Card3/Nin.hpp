struct Nin : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;
  
  static std::string description(){
    return
      argument::common::Nin::description() +
      " However, in the case of the MODER Card 3 nin argument, a value of zero\n"
      "is also permitted. A nin argument of zero signals that no additional\n"
      "MODER card 3 entries need be read. In this case, the matd MODER card 3\n"
      "argument should be defaulted by using a '/' following the MODER card 3\n"
      "nin argument. Beyond the typical constraints on nin arguments, the\n"
      "MODER card 3 nin argument is required to a absolute value distinct from\n"
      "that of the MODER card 1 nout argument.";
  }
  
  static bool verify( const Value_t v, const Argument< Card1::Nout >& nout ){
    return ( not v ) or
      ( ( std::abs(v) != std::abs(nout.value) )
	and argument::common::Nin::verify(v) );
  }
};
