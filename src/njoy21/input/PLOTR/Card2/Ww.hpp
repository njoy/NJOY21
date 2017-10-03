struct Ww {
  using Value_t = double;
  static std::string name(){ return "ww"; }
  static std::string description(){
    return
      "The ww argument specifies the window width of the current plot.\n"
      "When the wr argument is divisible by 90 (i.e. - right angle\n"
      "rotations), this argument determines the width of the plot ( i.e. -\n"
      "stretches the x-axis).\n\n"
      "The argument is a floating point value in inches.  The default is\n"
      "defined such that one plot will fit on a single page with 0.5 inch\n"
      "margins on all four sides.  Negative values are not permitted.\n\n"
      "Warning: if used with a wr argument that is not evenly divisible by\n"
      "90, the behavior is quite different.  In these cases, this argument\n"
      "is combined with the wh (window height) option, using the pythagorean\n"
      "theorem, to determine the distance from the point defined by the xll\n"
      "and yll options in the direction of the wr option, taken as degrees\n"
      "counter-clockwise from the positive x direction.  These two points\n"
      "are used as the opposite corners of a rectangle outside of which no\n"
      "image will be displayed and inside of which the plot will not be\n"
      "scaled to fit.  This does mean that all angles divisible by 45 but not\n"
      "by 90 will create a box of zero height or width resulting in a blank\n"
      "page.  As such, if using angles not evenly divisible by 90, a lot of\n"
      "tweaking will be required to get a complete plot drawn.";
  }
  static Value_t defaultValue( const int pgfmt ){
    if( pgfmt == 1 ) return 10.0;
    return 7.5;
  }
  static bool verify( Value_t v , const int ){
    return ( v > 0.0 and v <= 11.0 );
  }
};
