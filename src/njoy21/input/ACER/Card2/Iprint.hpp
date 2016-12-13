struct Iprint {
  using Value_t = int;
  static std::string name(){ return "iprint"; }

  static std::string description(){
    return
        "The iprint argument specifies the verbosity of the printed output. \n"
        "A value 0 produces the minimum amount of ouput (i.e., quiet) while \n"
        "a value of 1 produces the maximum.\n"
        "\n"
        "While this is an integer value and anything greater than 0 will \n"
        "result in the maximum amount of information printed, it is really a \n"
        "boolean switch to turn off (or on) the output.\n"
        "\n"
        "The default value of 1 produces a complete, interpreted listing of\n"
        "the ACE dataa. The whorter prit options (value 0) just put out \n"
        "progress information from the ACER job and a brief listing of the \n"
        "header information for the library that was generated.";
  }

  static int defaultValue(){ return 1; }
  static bool verify( Value_t i ){ return i >= 0; }
};

