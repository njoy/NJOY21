#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Validating card9 inputs",
          "[PLOTR], [Card9]" ){

  GIVEN( "valid PLOTR Card9 inputs" ){
    WHEN( "All values are given" ){
      std::vector<int> validIcon{-80,-10,0,10,80};
      std::vector<int> validIsym(19);
      std::iota(validIsym.begin(), validIsym.end(), 0);
      std::vector<int> validIdash{0,1,2,3,4};
      std::vector<int> validIccol{0,1,2,3,4,5,6,7,8};
      std::vector<int> validIthick{0,1};
      std::vector<int> validIshade(81);
      std::iota(validIshade.begin(), validIshade.end(), 0);

      for( auto icon : validIcon ){
        for( auto isym : validIsym ){
          for( auto idash : validIdash ){
            for( auto iccol : validIccol ){
              for( auto ithick : validIthick ){
                for( auto ishade : validIshade ){
                  auto str = 
                    std::to_string(icon) + " " +
                    std::to_string(isym) + " " +
                    std::to_string(idash) + " " +
                    std::to_string(iccol) + " " +
                    std::to_string(ithick) + " " +
                    std::to_string(ishade) + " /";

                  iRecordStream<char> issCard9( std::istringstream{ str } );
                  PLOTR::Card9 card9(issCard9);

                  THEN( "the members can be tested" ){
                    REQUIRE( icon == card9.icon.value );
                    REQUIRE( isym == card9.isym.value );
                    REQUIRE( idash == card9.idash.value );
                    REQUIRE( iccol == card9.iccol.value );
                    REQUIRE( ithick == card9.ithick.value );
                    REQUIRE( ishade == card9.ishade.value );
                  }//THEN
                }
                iRecordStream<char> issCard9( std::istringstream(
                  std::to_string(icon) + " " +
                  std::to_string(isym) + " " +
                  std::to_string(idash) + " " +
                  std::to_string(iccol) + " " +
                  std::to_string(ithick) + " /" ) );

                PLOTR::Card9 card9(issCard9);

                THEN( "the members can be tested" ){
                  REQUIRE( icon == card9.icon.value );
                  REQUIRE( isym == card9.isym.value );
                  REQUIRE( idash == card9.idash.value );
                  REQUIRE( iccol == card9.iccol.value );
                  REQUIRE( ithick == card9.ithick.value );
                  REQUIRE( 0 == card9.ishade.value );
                }//THEN
              }
              iRecordStream<char> issCard9( std::istringstream(
                std::to_string(icon) + " " +
                std::to_string(isym) + " " +
                std::to_string(idash) + " " +
                std::to_string(iccol) + " /" ) );

              PLOTR::Card9 card9(issCard9);

              THEN( "the members can be tested" ){
                REQUIRE( icon == card9.icon.value );
                REQUIRE( isym == card9.isym.value );
                REQUIRE( idash == card9.idash.value );
                REQUIRE( iccol == card9.iccol.value );
                REQUIRE( 1 == card9.ithick.value );
                REQUIRE( 0 == card9.ishade.value );
              }//THEN
            }
            iRecordStream<char> issCard9( std::istringstream(
              std::to_string(icon) + " " +
              std::to_string(isym) + " " +
              std::to_string(idash) + " /" ) );

            PLOTR::Card9 card9(issCard9);

            THEN( "the members can be tested" ){
              REQUIRE( icon == card9.icon.value );
              REQUIRE( isym == card9.isym.value );
              REQUIRE( idash == card9.idash.value );
              REQUIRE( 0 == card9.iccol.value );
              REQUIRE( 1 == card9.ithick.value );
              REQUIRE( 0 == card9.ishade.value );
            }//THEN
          }
          iRecordStream<char> issCard9( std::istringstream(
            std::to_string(icon) + " " +
            std::to_string(isym) + " /" ) );

          PLOTR::Card9 card9(issCard9);

          THEN( "the members can be tested" ){
            REQUIRE( icon == card9.icon.value );
            REQUIRE( isym == card9.isym.value );
            REQUIRE( 0 == card9.idash.value );
            REQUIRE( 0 == card9.iccol.value );
            REQUIRE( 1 == card9.ithick.value );
            REQUIRE( 0 == card9.ishade.value );
          }//THEN
        }
        iRecordStream<char> issCard9( std::istringstream(
          std::to_string(icon) + " /" ) );

        PLOTR::Card9 card9(issCard9);

        THEN( "the members can be tested" ){
          REQUIRE( icon == card9.icon.value );
          REQUIRE( 0 == card9.isym.value );
          REQUIRE( 0 == card9.idash.value );
          REQUIRE( 0 == card9.iccol.value );
          REQUIRE( 1 == card9.ithick.value );
          REQUIRE( 0 == card9.ishade.value );
        }//THEN
      }
      iRecordStream<char> issCard9( std::istringstream( " /" ) );

      PLOTR::Card9 card9(issCard9);

      THEN( "the members can be tested" ){
        REQUIRE( 0 == card9.icon.value );
        REQUIRE( 0 == card9.isym.value );
        REQUIRE( 0 == card9.idash.value );
        REQUIRE( 0 == card9.iccol.value );
        REQUIRE( 1 == card9.ithick.value );
        REQUIRE( 0 == card9.ishade.value );
      }//THEN
    } //WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "All values are wrong" ){
      iRecordStream<char> issCard9( std::istringstream(
             "1.1 -1 5 22 -8 99 /" ) );
  
      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card9(issCard9) );
      }
    }//WHEN
    WHEN( "One value is wrong" ){
      {
        iRecordStream<char> issCard9( std::istringstream(
              "10 17 5 3 0 43 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card9(issCard9) );
        }
      }{
        iRecordStream<char> issCard9( std::istringstream(
              "-8 11 2 9 /" ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( PLOTR::Card9(issCard9) );
        }
      }
    }//WHEN
    WHEN( "An extra value is given" ){
      iRecordStream<char> issCard9( std::istringstream(
            "10 18 0 1 1 71 1 /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( PLOTR::Card9(issCard9) );
      }
    }//WHEN
  }//GIVEN
}//SCENARIO
