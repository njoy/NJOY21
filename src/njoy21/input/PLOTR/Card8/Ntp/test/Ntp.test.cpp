#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

//  Test matrix:
//  - All default to 1
//
//  - mfd = 3 or 5 and iverf != 1 -> not used
//  - mfd = 4 and iverf != 1 -> not used
//  - mfd = 6 and iverf != 1
//  - mfd = 3 and iverf == 1
//  - mfd = 6 and iverf == 1 -> not used
//  - mfd = 7 and iverf != 1

SCENARIO( "Ntp input values", "[PLOTR], [Card8], [Ntp]" ){
  GIVEN( "valid ntp values" ){
    WHEN( "mfd = 6 and iverf != 1" ){
      std::vector<int> validNtp{ 1, 5, 30 };
      int mfd = 6; int iverf = 3;
      THEN( "the returned value is correct" ){
        for( auto ntp : validNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Ntp >(
                   issNtp, mfd, iverf ).value == ntp );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNtp( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Ntp >(
                 issNtp, mfd, iverf ).value == 1 );
      }
    }
    WHEN( "mfd = 3 and iverf == 1" ){
      std::vector<int> validNtp{ 1, 2 };
      int mfd = 3; int iverf = 1;
      THEN( "the returned value is correct" ){
        for( auto ntp : validNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Ntp >(
                   issNtp, mfd, iverf ).value == ntp );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNtp( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Ntp >(
                 issNtp, mfd, iverf ).value == 1 );
      }
    }
    WHEN( "mfd = 7 and iverf != 1 and jtype == 0" ){
      std::vector<int> validNtp{ 1, 2 };
      int mfd = 7; int iverf = 5;
      THEN( "the returned value is correct" ){
        for( auto ntp : validNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Ntp >(
                   issNtp, mfd, iverf ).value == ntp );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNtp( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Ntp >(
                 issNtp, mfd, iverf ).value == 1 );
      }
    }
  }//GIVEN
  GIVEN( "invalid ntp values" ){
    WHEN( "mfd = 3 and iverf != 1, this value is not used" ){
      std::vector<int> invalidNtp{ -10, -1, 0, 1, 5, 10, 50};
      int mfd = 3; int iverf = 2;
      THEN( "an exception is thrown" ){
        for( auto ntp : invalidNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Ntp >(
                          issNtp, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 5 and iverf != 1, this value is not used" ){
      std::vector<int> invalidNtp{ -10, -1, 0, 1, 5, 10, 50 };
      int mfd = 5; int iverf = 2;
      THEN( "an exception is thrown" ){
        for( auto ntp : invalidNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Ntp >(
                          issNtp, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 4 and iverf != 1, this value is not used" ){
      std::vector<int> invalidNtp{ -10, -2, -1, 0, 1, 5, 30 };
      int mfd = 4; int iverf = 2;
      THEN( "an exception is thrown" ){
        for( auto ntp : invalidNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Ntp >(
                          issNtp, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 6 and iverf != 1" ){
      std::vector<int> invalidNtp{ 0, -10, -2, -1 };
      int mfd = 6; int iverf = 3;
      THEN( "an exception is thrown" ){
        for( auto ntp : invalidNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Ntp >(
                          issNtp, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 3 and iverf == 1" ){
      std::vector<int> invalidNtp{ -2, -1, 0, 3, 5 };
      int mfd = 3; int iverf = 1;
      THEN( "an exception is thrown" ){
        for( auto ntp : invalidNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Ntp >(
                          issNtp, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 6 and iverf == 1, this value isn't used" ){
      std::vector<int> invalidNtp{ -10, -5, -1, 0, 1, 2, 5, 10, 288 };
      int mfd = 6; int iverf = 1;
      THEN( "an exception is thrown" ){
        for( auto ntp : invalidNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Ntp >(
                          issNtp, mfd, iverf ) );
        }
      }
    }
    WHEN( "mfd = 7 and iverf != 1 and jtype == 0" ){
      std::vector<int> invalidNtp{ -10, -2, -1, 0, 3, 5, 10 };
      int mfd = 7; int iverf = 3;
      THEN( "an exception is thrown" ){
        for( auto ntp : invalidNtp ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Ntp >(
                          issNtp, mfd, iverf ) );
        }
      }
    }
  }//GIVEN
  GIVEN( "iverf == 0" ){
    int iverf = 0;
    std::vector<int> mfds{ -10, -5, 0, 1, 5, 10, 20 };
    THEN( "the values don't matter" ){
      for( auto mfd : mfds ){
        for( auto ntp : mfds ){
          iRecordStream<char> issNtp( std::istringstream(
                               std::to_string(ntp) ) );
          REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Ntp >(
                            issNtp, mfd, iverf ) );
        }
      }
    }
  }//GIVEN
}

