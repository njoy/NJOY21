#include "tclap/CmdLine.h"

namespace TCLAP {

template<>
struct ArgTraits< std::optional< std::string > > {
  using ValueCategory = StringLike;
};

}

struct njoy::njoy21::CommandLine {
  /* fields (with default initialization) */
  std::optional< std::string > inputPath;
  std::optional< std::string > outputPath;
  std::optional< std::string > errorPath;
  bool legacySwitch;
  bool verifyOnly;
  bool signature;
  
  /* methods */
#include "njoy21/CommandLine/src/ctor.hpp"

};
