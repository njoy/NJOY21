struct Size {
  using Value_t = double;
  static std::string name(){ return "size"; }
  static std::string description(){
    return
      "The size argument specifies the character size option for the plot\n"
      "defined in the rest of the PLOTR input.\n\n"
      "The value is a floating point number.\n"
      "If the value is negative, the value is the height of the characters\n"
      "as a fraction of the subplot size.\n"
      "If the value is positive, the value is the height of the characters\n"
      "in page units.\n"
      "The default value is 0.30 specifying the character height is\n"
      "0.30 page units.";
  }
  static double defaultValue(){ return 0.30; }
  static bool verify( Value_t v ){
    return ( std::abs(v) <= 1.0 and v != 0.0);
  }
};
