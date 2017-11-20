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

SCENARIO( "Eh output values", "[PLOTR],[Card5], [Eh]"){


  GIVEN( "valid entries" ){
    WHEN( "valid Eh parameters" ){
      std::optional< double > el = 0.0;
  
      std::vector<double> validValues{0.01,0.1,0.5,0.8,1.0,2.0,80.0};
  
      THEN( "the returned class has the correct value" ){
        for( auto eh : validValues ){
          iRecordStream<char> issEh( 
              std::istringstream( std::to_string( eh ) ) );
  
          REQUIRE( eh == *( argument::extract< PLOTR::Card5::Eh >( 
                            issEh, el ).value ) );
        }
      }
    }
  
    WHEN( "default value" ){
      std::optional< double > el;
      iRecordStream<char> issEh( std::istringstream( " /" ) );
      
      THEN( "default value is returned" ){
        REQUIRE( std::nullopt == argument::extract< PLOTR::Card5::Eh >(
                            issEh, el ).value );
      }
    }
  }

  GIVEN( "invalid Eh parameters" ){
    std::optional< double > el = 5.0;

    WHEN( "eh uses the default value, but el doesn't" ){
      iRecordStream<char> issEh( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( argument::extract< PLOTR::Card5::Eh > ( issEh, el ) );
      }
    }

    std::vector<double> invalidValues{ -2.0, -1.1, 4.5 };

    WHEN( "eh has a value less than el" ){
      for( auto eh : invalidValues ){
        iRecordStream<char> issEh( 
            std::istringstream( std::to_string( eh ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< PLOTR::Card5::Eh >( issEh, el ) );
        }
      }
    }
  } // GIVEN
} // SCENARIO
