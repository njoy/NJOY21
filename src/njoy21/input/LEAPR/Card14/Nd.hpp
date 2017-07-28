struct Nd {
  using Value_t = int;
  static std::string name(){ return "nd"; }
  static std::string description(){
    return
      "The nd input is an integer input to indicate the number of discrete\n"
      "oscillators. nd can equal zero.\n"
      "\n"
      "Choice of discrete oscillators must be such that:\n"
      "   wt + ws + ( w_1 + w_2 + ... + w_nd ) = 1   \n"
      "where wt is the translational weight (twt from Card13), ws is the\n"
      "weight for solid type law, and w_i is the weight of the ith discrete\n"
      "oscillator (given on card16).";
  } 
  static bool verify( const Value_t nd ){ return nd >= 0; }
};
