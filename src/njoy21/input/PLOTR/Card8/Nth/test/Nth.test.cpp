#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

//  Test matrix:
//  - All default to 1
//
//  - mfd = 3 or 5 and iverf != 1
//  - mfd = 4 and iverf != 1
//  - mfd = 6 and iverf != 1
//  - mfd = 3 and iverf == 1
//  - mfd = 6 and iverf == 1 and jtype == 0
//  - mfd = 7 and iverf != 1

SCENARIO( "Nth input values", "[PLOTR], [Card8], [Nth]" ){
  GIVEN( "valid nth values" ){
    WHEN( "mfd = 3 and iverf != 1" ){
      std::vector<int> validNth{ 1, 5, 10, 50 };
      int mfd = 3; int iverf = 2; int jtype = 0;
      THEN( "the returned value is correct" ){
        for( auto nth : validNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                   issNth, mfd, iverf, jtype ).value == nth );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNth( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                 issNth, mfd, iverf, jtype ).value == 1 );
      }
    }
    WHEN( "mfd = 5 and iverf != 1" ){
      std::vector<int> validNth{ 1, 5, 10, 50 };
      int mfd = 5; int iverf = 2; int jtype = 0;
      THEN( "the returned value is correct" ){
        for( auto nth : validNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                   issNth, mfd, iverf, jtype ).value == nth );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNth( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                 issNth, mfd, iverf, jtype ).value == 1 );
      }
    }
    WHEN( "mfd = 4 and iverf != 1" ){
      std::vector<int> validNth{ 0, 1, 5, 30 };
      int mfd = 4; int iverf = 2; int jtype = 0;
      THEN( "the returned value is correct" ){
        for( auto nth : validNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                   issNth, mfd, iverf, jtype ).value == nth );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNth( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                 issNth, mfd, iverf, jtype ).value == 1 );
      }
    }
    WHEN( "mfd = 6 and iverf != 1" ){
      std::vector<int> validNth{ 0, 1, 5, 30 };
      int mfd = 6; int iverf = 3; int jtype = 0;
      THEN( "the returned value is correct" ){
        for( auto nth : validNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                   issNth, mfd, iverf, jtype ).value == nth );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNth( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                 issNth, mfd, iverf, jtype ).value == 1 );
      }
    }
    WHEN( "mfd = 3 and iverf == 1" ){
      std::vector<int> validNth{ 0, 1 };
      int mfd = 3; int iverf = 1; int jtype = 0;
      THEN( "the returned value is correct" ){
        for( auto nth : validNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                   issNth, mfd, iverf, jtype ).value == nth );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNth( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                 issNth, mfd, iverf, jtype ).value == 1 );
      }
    }
    WHEN( "mfd = 6 and iverf == 1 and jtype == 0" ){
      std::vector<int> validNth{ 1, 2, 5, 10, 288 };
      int mfd = 6; int iverf = 1; int jtype = 0;
      THEN( "the returned value is correct" ){
        for( auto nth : validNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                   issNth, mfd, iverf, jtype ).value == nth );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNth( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                 issNth, mfd, iverf, jtype ).value == 1 );
      }
    }
    WHEN( "mfd = 7 and iverf != 1 and jtype == 0" ){
      std::vector<int> validNth{ 0, 1, 2, 5, 10, 288 };
      int mfd = 7; int iverf = 2; int jtype = 0;
      THEN( "the returned value is correct" ){
        for( auto nth : validNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                   issNth, mfd, iverf, jtype ).value == nth );
        }
      }
      THEN( "the default value is returned" ){
        iRecordStream<char> issNth( std::istringstream( " /" ) );
        REQUIRE( argument::extract< PLOTR::Card8::Nth >(
                 issNth, mfd, iverf, jtype ).value == 1 );
      }
    }
  }//GIVEN
  GIVEN( "invalid nth values" ){
    WHEN( "mfd = 3 and iverf != 1" ){
      std::vector<int> invalidNth{ -10, -1, 0};
      int mfd = 3; int iverf = 2; int jtype = 0;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                          issNth, mfd, iverf, jtype ) );
        }
      }
    }
    WHEN( "mfd = 5 and iverf != 1" ){
      std::vector<int> invalidNth{ -10, -1, 0 };
      int mfd = 5; int iverf = 2; int jtype = 0;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                          issNth, mfd, iverf, jtype ) );
        }
      }
    }
    WHEN( "mfd = 4 and iverf != 1" ){
      std::vector<int> invalidNth{ -10, -2, -1 };
      int mfd = 4; int iverf = 2; int jtype = 0;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                          issNth, mfd, iverf, jtype ) );
        }
      }
    }
    WHEN( "mfd = 6 and iverf != 1" ){
      std::vector<int> invalidNth{ -10, -2, -1 };
      int mfd = 3; int iverf = 3; int jtype = 0;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                          issNth, mfd, iverf, jtype ) );
        }
      }
    }
    WHEN( "mfd = 3 and iverf == 1" ){
      std::vector<int> invalidNth{ -2, -1, 2, 5 };
      int mfd = 3; int iverf = 1; int jtype = 0;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                          issNth, mfd, iverf, jtype ) );
        }
      }
    }
    WHEN( "mfd = 6 and iverf == 1 and jtype == 0" ){
      std::vector<int> invalidNth{ -10, -1, 0 };
      int mfd = 6; int iverf = 1; int jtype = 0;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                          issNth, mfd, iverf, jtype ) );
        }
      }
    }
    WHEN( "mfd = 6 and iverf == 1 and jtype == 1, this value isn't used" ){
      std::vector<int> invalidNth{ -10, -5, -1, 0, 1, 2, 5, 10, 288 };
      int mfd = 6; int iverf = 1; int jtype = 1;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                         issNth, mfd, iverf, jtype ) );
        }
      }
    }
    WHEN( "mfd = 7 and iverf != 1 and jtype == 0" ){
      std::vector<int> invalidNth{ -10, -2, -1 };
      int mfd = 7; int iverf = 1; int jtype = 0;
      THEN( "an exception is thrown" ){
        for( auto nth : invalidNth ){
          iRecordStream<char> issNth( std::istringstream(
                               std::to_string(nth) ) );
          REQUIRE_THROWS( argument::extract< PLOTR::Card8::Nth >(
                          issNth, mfd, iverf, jtype ) );
        }
      }
    }
  }//GIVEN
  GIVEN( "iverf == 0" ){
    int iverf = 0;
    std::vector<int> mfds{ -10, -5, 0, 1, 5, 10, 20 };
    THEN( "the values don't matter" ){
      for( auto mfd : mfds ){
        for( auto jtype : mfds ){
          for( auto nth : mfds ){
            iRecordStream<char> issNth( std::istringstream(
                                 std::to_string(nth) ) );
            REQUIRE_NOTHROW( argument::extract< PLOTR::Card8::Nth >(
                              issNth, mfd, iverf, jtype ) );
          }
        }
      }
    }
  }//GIVEN
}

