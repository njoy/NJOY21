#define CATCH_CONFIG_MAIN

#include <numeric>

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "El output values", "[PLOTR],[Card5], [El]"){

  GIVEN( "Valid entries" ){

    for( auto itype : {-2,-1,1,2} ){
      std::string situ( "valid El value with itype == linear (" +
                                               std::to_string( itype ) + ")." );
      WHEN( situ.c_str() ){
      std::vector<double> validValues{0.0,0.1,0.5,0.8,1.0,2.0,80.0};

        THEN( "the returned class has the correct value" ){
          for( auto el : validValues ){
            iRecordStream<char> issEl( 
                std::istringstream( std::to_string( el ) ) );
    
            REQUIRE( el == *( argument::extract< PLOTR::Card5::El >( 
                              issEl, itype ).value ) );
          }
        }
      }
    }

    for( auto itype : {-4,-3,3,4} ){
      std::string situ( "valid El value with itype == logarithmic (" +
                                               std::to_string( itype ) + ")." );
      WHEN( situ.c_str() ){
        std::vector<double> validValues{0.1,0.5,0.8,1.0,2.0,80.0};
  
        THEN( "the returned class has the correct value" ){
          for( auto el : validValues ){
            iRecordStream<char> issEl( 
                std::istringstream( std::to_string( el ) ) );
    
            REQUIRE( el == *( argument::extract< PLOTR::Card5::El >( 
                              issEl, itype ).value ) );
          }
        }
      }
    }

    for( auto itype : {-4,-3,-2,-1,1,2,3,4} ){
      std::string situ( "default value is used with itype = " +
                                                      std::to_string( itype ) );
      WHEN( situ.c_str() ){
      iRecordStream<char> issEl( std::istringstream( " /" ) );
  
        THEN( "default value is returned" ){
          auto el_arg = argument::extract< PLOTR::Card5::El >( issEl, itype);
          REQUIRE( el_arg.defaulted );
          REQUIRE( std::nullopt == el_arg.value );
        }
      }
    }
  }//GIVEN

  GIVEN( "invalid parameters" ){

    WHEN( "invalid El parameters for linear scale" ){
      std::vector<double> invalidValues{ -2.0, -1.1 };
  
      THEN( "the class throws an exception" ){
        for( auto itype : {-2,-1,1,2} ){
          for( auto el : invalidValues ){
            iRecordStream<char> issEl( 
                std::istringstream( std::to_string( el ) ) );
    
            REQUIRE_THROWS( argument::extract< PLOTR::Card5::El >(
                             issEl, itype ) );
          }
        }
      }
    }
  
    WHEN( "invalid El parameters for log scale" ){
      std::vector<double> invalidValues{ -2.0, -1.1, 0.0 };
  
      THEN( "the class throws an exception" ){
        for( auto itype : {-4,-3,3,4} ){
          for( auto el : invalidValues ){
            iRecordStream<char> issEl( 
                std::istringstream( std::to_string( el ) ) );
    
            REQUIRE_THROWS( argument::extract< PLOTR::Card5::El >(
                             issEl, itype ) );
          }
        }
      }
    }
  } // GIVEN
} // SCENARIO
