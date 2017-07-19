class HEATR {
public:
  #include "njoy21/input/HEATR/Card1.hpp"
  #include "njoy21/input/HEATR/Card2.hpp"
  #include "njoy21/input/HEATR/Card3.hpp"
  #include "njoy21/input/HEATR/Card4.hpp"
  #include "njoy21/input/HEATR/Card5.hpp"
  #include "njoy21/input/HEATR/Card5a.hpp"

  #include "njoy21/input/HEATR/src/buildCard3.hpp"
  #include "njoy21/input/HEATR/src/buildControlTuple.hpp"
  #include "njoy21/input/HEATR/src/ctor.hpp"

  Card1 card1;
  Card2 card2;
  optional<Card3> card3;
  optional<ControlTuple> controlTuple;

};
