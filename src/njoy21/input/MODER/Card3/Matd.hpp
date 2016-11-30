struct Matd : public argument::common::Matd {
  using Value_t = argument::common::Matd::Value_t;
  
  static std::string description(){
    return
      argument::common::Matd::description() +
      "\n\n"
      "The material corresponding to the MAT number will be copied from the \n"
      "tape specified by the MODER Card 3 nin argument to an output tape \n"
      "specified by the MODER Card 1 nout argument. Consequently, this field\n"
      "should only be specified when the MODER Card 3 nin argument is nonzero.";
  }

  static Value_t defaultValue(){ return 0; }
};
