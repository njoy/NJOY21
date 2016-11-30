struct Nin : public argument::common::Nin {
  using Value_t = argument::common::Nin::Value_t;
  
  static std::string description(){
    return
      argument::common::Nin::description() +
      " However, in the case of the MODER Card 1 nin argument,\n"
      "three additional argument values are permitted: 1, 2, 3. These values\n"
      "indicate that individual materials are to be selected from one or more\n"
      "input tapes (see MODER card 3) with or without format modifications.\n"
      "\n"
      "In this case, the nin argument value specifies the input tape file format:\n"
      "    nin == 1 : ENDF or pENDF input and output\n"
      "    nin == 2 : gENDF input and output\n"
      "    nin == 3 : ERRORR input and output\n"
      "\n"
      "See cards 2 and 3 for more information regarding this mode of operation";
  }
  
  static bool verify( const Value_t v ){
    return ( ( v > 0 )  and ( v < 4 ) ) or argument::common::Nin::verify(v);
  }
};
