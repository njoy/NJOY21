#define CATCH_CONFIG_MAIN

#include <numeric>

#ifdef USING_CPP17
  #include <optional>
#else 
  #include <experimental/optional>

  namespace std {
    using namespace std::experimental;
  }
#endif

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "Rstep output values", "[PLOTR],[Card7], [Rstep]"){

  std::optional< double > rbot = 0.0;

  GIVEN( "valid Rstep parameters" ){
    std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};

    THEN( "the returned class has the correct value" ){
      for( auto rstep : validValues ){
        iRecordStream<char> issRstep( 
            std::istringstream( std::to_string( rstep ) ) );

        REQUIRE( rstep == *( argument::extract< PLOTR::Card7::Rstep >( 
                          issRstep, rbot ).value ) );
      }
    }
  } // GIVEN

  GIVEN( "default value" ){
    iRecordStream<char> issRstep( std::istringstream( " /" ) );

    THEN( "default value is returned" ){
      REQUIRE( std::nullopt == argument::extract< PLOTR::Card7::Rstep >(
                          issRstep, std::optional<double>() ).value );
    }
  }//GIVEN

  GIVEN( "invalid Rstep parameters" ){

    WHEN( "invalid values are given" ){
      std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };
  
      THEN( "the class throws an exception" ){
        for( auto rstep : invalidValues ){
          iRecordStream<char> issRstep( 
              std::istringstream( std::to_string( rstep ) ) );
  
          REQUIRE_THROWS( argument::extract< PLOTR::Card7::Rstep >( issRstep, rbot ) );
        }
      }
    }

    WHEN( "Rstep is defaulted, but rbot wasn't" ){
      iRecordStream<char> issRstep( std::istringstream( " / " ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< PLOTR::Card7::Rstep >( issRstep, rbot ) );
      }
    }
  } // GIVEN
} // SCENARIO
