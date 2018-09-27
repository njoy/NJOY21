#include "tclap/CmdLine.h"

namespace TCLAP {

template<>
struct ArgTraits< std::experimental::optional< std::string > > {
  using ValueCategory = StringLike;
};

}

struct njoy::njoy21::CommandLine {
  /* fields (with default initialization) */
  optional< std::string > inputPath;
  optional< std::string > outputPath;
  bool legacySwitch;
  bool verifyOnly;
  
  /* methods */
#include "njoy21/CommandLine/src/ctor.hpp"

};
