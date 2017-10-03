#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "El output values", "[PLOTR],[Card5], [El]"){

  std::vector<int> itype{1,2,3,4};

  GIVEN( "valid El parameters with itype == 1" ){
    std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto el : validValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE( el == argument::extract< PLOTR::Card5::El >( 
                          issEl, itype[0] ).value );
      }
    }
  } // GIVEN

  GIVEN( "valid El parameters with itype == 2" ){
    std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto el : validValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE( el == argument::extract< PLOTR::Card5::El >( 
                          issEl, itype[1] ).value );
      }
    }
  } // GIVEN

  GIVEN( "valid El parameters with itype == 3" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto el : validValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE( el == argument::extract< PLOTR::Card5::El >( 
                          issEl, itype[2] ).value );
      }
    }
  } // GIVEN

  GIVEN( "valid El parameters with itype == 4" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto el : validValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE( el == argument::extract< PLOTR::Card5::El >( 
                          issEl, itype[3] ).value );
      }
    }
  } // GIVEN

  GIVEN( "default value for linear scale" ){
    iRecordStream<char> issEl( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( APPROX( 0.0 ) == argument::extract< PLOTR::Card5::El >(
                          issEl, itype[0] ).value );
    }
  }//GIVEN

  GIVEN( "default value for log scale" ){
    iRecordStream<char> issEl( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( APPROX( 1.0e-07 ) == argument::extract< PLOTR::Card5::El >(
                          issEl, itype[2] ).value );
    }
  }//GIVEN

  GIVEN( "invalid El parameters for linear scale" ){
    std::vector<double> invalidValues{ -2.0, -1.1 };

    THEN( "the class throws an exception" ){
      for( auto el : invalidValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card5::El >(
                         issEl, itype[ 1 ] ) );
      }
    }
  } // GIVEN

  GIVEN( "invalid El parameters for log scale" ){
    std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };

    THEN( "the class throws an exception" ){
      for( auto el : invalidValues ){
        iRecordStream<char> issEl( 
            std::istringstream( std::to_string( el ) ) );

        REQUIRE_THROWS( argument::extract< PLOTR::Card5::El >(
                         issEl, itype[ 3 ] ) );
      }
    }
  } // GIVEN
} // SCENARIO
