struct Infile {
  using Value_t = int;

  static std::string name() { return "infile"; }

  static std::string description() {
	return 
		"The infile argument specifies to the io unit used internally by the\n"
		"Fortran routine and the filename ot be read in, e.g. setting infile to\n"
		"21 or -21 implies a file named 'tape 21' is available in the working\n"
		"directory.\n"
		"\n"
		"The signedness of the argument implies the formatting of the file in\n"
		"question. Positive argument values indicate formatted input i.e.\n"
		"ascii text files. Negative values indicate unformatted input i.e.\n"
		"Fortran-style block binary.\n"
		"\n"
		"infile values are restricted to an absolute value between 20\n"
		"and 99, inclusively.";
  	}	

  static bool verify( const Value_t& i ){ return std::abs(i) >= 20 && std::abs(i) <= 99; }
  
};
