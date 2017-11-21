struct Nout : public argument::common::Nout {
  
  using Value_t = argument::common::Nout::Value_t;
  
  static std::string description(){
    return
      argument::common::Nout::description() +
      "\nHowever, in the case of the MODER Card 1 nout argument, the former\n"
      "restriction is lifted, allowing conversion between binary- and \n"
      "ascii-format (or vice-versa) between the input and output tapes.";
  }

  static bool verify( const Value_t v, const Argument<Nin>& nin ){
    return argument::common::Nout::verify( v )
        && ( std::abs(nin.value) != std::abs(v) );
  }
};
