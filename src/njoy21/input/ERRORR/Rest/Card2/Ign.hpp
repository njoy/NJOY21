struct Ign {
  using Value_t = int;
  static std::string name(){ return "ign"; }
  static std::string description(){
    return "The ign parameter specifies the neutron group option.  The\n"
           "definition is the same as GROUPR, except that ign=19, which\n"
           "means read in an energy grid, as in ign=1, and supplement\n"
           "this with the endf covariance grid within the range of the\n"
           "user-specified energies.\n\n"
           "ign        meaning\n"
           "---        -------\n"
           " 1         arbitrary structure (read in) (default)\n"
           " 2         csewg 239-group structure\n"
           " 3         lanl 30-group structure\n"
           " 4         anl 27-group structure\n"
           " 5         rrd 50-group structure\n"
           " 6         gam-i 68-group structure\n"
           " 7         gam-ii 100-group structure\n"
           " 8         laser-thermos 35-group structure\n"
           " 9         epri-cpm 69-group structure\n"
           "10         lanl 187-group structure\n"
           "11         lanl 70-group structure\n"
           "12         sand-ii 620-group structure\n"
           "13         lanl 80-group structure\n"
           "14         eurlib 100-group structure\n"
           "15         sand-iia 640-group structure\n"
           "16         vitamin-e 174-group structure\n"
           "17         vitamin-j 175-group structure\n"
           "18         xmas 172-group structure\n"
           "19         read in, supplemented with endf covariance grid";
  }
  static Value_t defaultValue(){ return 1; }
  static bool verify( const Value_t ign ){
    return ( ign < 20 and ign > 0 );
  }
};
