struct Temp2 {
  using Value_t = Quantity< Kelvin >;
  static std::string name(){ return "temp2"; }
  static std::string description(){
    return
      "temp2 is an argument specifying a temperature in Kelvin. The argument\n"
      "value specifies the final temperature to which reference temperature\n"
      "(see card 2 temp1 argument) cross sections should be broadened.\n"
      "\n"
      "temp2 is required to be greater than or equal to the corresponding\n"
      "card 2 temp1 argument. In the case that the temp2 value is equal to\n"
      "the temp1 value, the cross sections are thinned only.";
  }

  static bool verify( Value_t v, const Argument< Card2::Temp1 >& temp1 ){
    return v >= temp1.value;
  }
};
