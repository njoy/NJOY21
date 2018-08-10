template< typename Char >
class FortranString {
  std::basic_string<Char>& core;
  typename std::char_traits<Char>::int_type buffer;
  char quote;

#include "njoy21/input/argument/parser/FortranString/src/isQuote.hpp"
#include "njoy21/input/argument/parser/FortranString/src/quoted.hpp"
#include "njoy21/input/argument/parser/FortranString/src/unquoted.hpp"

public:
  FortranString( std::basic_string<Char>& core ) : core( core ){
    this->core.clear();
  }
  
#include "njoy21/input/argument/parser/FortranString/src/read.hpp"
};
