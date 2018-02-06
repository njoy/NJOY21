#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "POWR",
          "[POWR]" ){
  GIVEN( "valid inputs" ){
    WHEN( "using lib=1" ){
      std::string inp(
 " 27 29 /\n" // Card1
 " 1 0 0 /\n" // Card2
 " 9439 279.0 0 2 2 /\n" // Card3
 " 'word value' /\n" // Card4
 " 'fsn value' /\n" // Card5
 " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9\n" 
 " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9\n" 
 " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9\n" 
 " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9\n" 
 " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9\n" 
 " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9\n" 
 " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 /\n" // Card6
 " 0 /" // Terminating Card3
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        POWR powr( iss );

        REQUIRE( 27 == powr.card1.ngendf.value );
        REQUIRE( 29 == powr.card1.nout.value );

        REQUIRE( 1 == powr.card2.lib.value );
        REQUIRE( 0 == powr.card2.iprint.value );
        REQUIRE( 0 == powr.card2.iclaps.value );

        REQUIRE( 9439 == std::experimental::get<0>( powr.lib ).at(0).card3.matd.value );
        REQUIRE( 279.0*dimwits::kelvin ==
                std::get<0>( *( std::experimental::get<0>( powr.lib ).at(0).card3.rest ) ).value );
        REQUIRE( 0 == 
                std::get<1>( *( std::experimental::get<0>( powr.lib ).at(0).card3.rest ) ).value );
        REQUIRE( 2 ==
                std::get<2>( *( std::experimental::get<0>( powr.lib ).at(0).card3.rest ) ).value );
        REQUIRE( 2 == 
                std::get<3>( *( std::experimental::get<0>( powr.lib ).at(0).card3.rest ) ).value );

        REQUIRE( "word value" == 
                      std::experimental::get<0>( powr.lib ).at(0).card45->first.word.value );

        REQUIRE( "fsn value" == 
                        std::experimental::get<0>( powr.lib ).at(0).card45->second.fsn.value );

        for( int i = 0; i < 68; i++ ){
          double d( i*0.1 );
          REQUIRE( Approx( d ) == 
                         std::experimental::get<0>( powr.lib ).at(0).card6->abs.value.at(i) );
        }
      }
    } // WHEN

    WHEN( "lib=2" ){
      std::string inp(
 std::string( " 95 99 /\n" ) + // Card1
 std::string( " 2 1 0 /\n" ) + // Card2
 std::string( " 2345 3.14 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 0 /" ) // Terminating Card3
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        POWR powr( iss );

        REQUIRE( 95 == powr.card1.ngendf.value );
        REQUIRE( 99 == powr.card1.nout.value );

        REQUIRE( 2 == powr.card2.lib.value );
        REQUIRE( 1 == powr.card2.iprint.value );
        REQUIRE( 0 == powr.card2.iclaps.value );

        REQUIRE( 2345 == std::experimental::get<1>( powr.lib ).at(0).card3.matd.value );
        REQUIRE( 3.14*dimwits::kelvin == 
                       std::experimental::get<1>( powr.lib ).at(0).card3.rest->first.value );
        REQUIRE( "hollerith" == 
                        std::experimental::get<1>( powr.lib ).at(0).card3.rest->second.value );

        REQUIRE( 1 == std::experimental::get<1>( powr.lib ).at(0).card45->first.itrc.value );
        REQUIRE( 2 == std::experimental::get<1>( powr.lib ).at(0).card45->first.mti.value );
        REQUIRE( 3 == std::experimental::get<1>( powr.lib ).at(0).card45->first.mtc.value );

        REQUIRE( Approx( 0.1 ) ==
                         std::experimental::get<1>( powr.lib ).at(0).card45->second.xi.value );
        REQUIRE( Approx( 0.2 ) ==
                      std::experimental::get<1>( powr.lib ).at(0).card45->second.alpha.value );
        REQUIRE( Approx( 0.3 ) ==
                      std::experimental::get<1>( powr.lib ).at(0).card45->second.mubar.value );
        REQUIRE( Approx( 0.4 ) ==
                         std::experimental::get<1>( powr.lib ).at(0).card45->second.nu.value );
        REQUIRE( Approx( 0.5 ) == 
               std::experimental::get<1>( powr.lib ).at(0).card45->second.kappaFission.value );
        REQUIRE( Approx( 0.6 ) == 
               std::experimental::get<1>( powr.lib ).at(0).card45->second.kappaCapture.value );
        REQUIRE( Approx( 0.7 ) ==
                     std::experimental::get<1>( powr.lib ).at(0).card45->second.lambda.value );
        REQUIRE( Approx( 0.8 ) ==
                     std::experimental::get<1>( powr.lib ).at(0).card45->second.sigmaS.value );
      }
    } // WHEN

    WHEN( "lib=3" ){
      std::string inp(
 std::string( " 50 60 /\n" ) + // Card1
 std::string( " 3 0 0 /\n" ) + // Card2
 std::string( " 1 20000201 2 0 0 2 1 /\n" ) + // Card3
 std::string( " 1200 9439 /\n" ) + // Card4
 std::string( " 3 2 3 4.0 1 5.0 6 7 0 0 8 9 /\n" ) + // Card5-1
 std::string( " 1 0 0 1.0 2 3 0 1 4 5 /\n" ) + // Card5-2
 std::string( " 2 1 /\n" ) + // Card6
 std::string( " 9439 /\n" ) + // Card7
 std::string( " 1200 0.5 /\n" ) + // Card8-1
 std::string( " 9439 1.0 0.2 0.3 0.5 /\n" ) + // Card8-2
 std::string( " 1200.0 0 1 /\n" ) + // Card9-1
 std::string( " 239.0 1 2 /\n" ) + // Card9-2
 std::string( " 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0 1.1 1.2 /\n" ) + // Card10
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 3.0 3.1 3.2 /\n" ) + // Card11
 std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 5.0 5.1 5.2 /\n" ) + // Card11a
 std::string( " 100.0 101.0 0.0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 " ) +
 std::string( " 1.0 1.1 1.2 1.3 1.4 1.5 1.6 1.7 1.8 1.9 " ) +
 std::string( " 2.0 2.1 2.2 2.3 2.4 2.5 2.6 2.7 2.8 2.9 " ) +
 std::string( " 3.0 3.1 3.2 3.3 3.4 3.5 3.6 3.7 3.8 3.9 " ) +
 std::string( " 4.0 4.1 4.2 4.3 4.4 4.5 4.6 4.7 4.8 4.9 " ) +
 std::string( " 5.0 5.1 5.2 5.3 5.4 5.5 5.6 5.7 5.8 5.9 " ) +
 std::string( " 6.0 6.1 6.2 6.3 6.4 6.5 6.6 6.7 6.8 /\n" ) + // Card12
 std::string( " 7.0 7.1 7.2 7.3 7.4 7.5 7.6 7.7 7.8 7.9 " ) +
 std::string( " 8.0 8.1 8.2 8.3 8.4 8.5 8.6 8.7 8.8 8.9 " ) +
 std::string( " 9.0 9.1 9.2 9.3 9.4 9.5 9.6 9.7 9.8 9.9 " ) +
 std::string( " 10.0 10.1 10.2 10.3 10.4 10.5 10.6 10.7 10.8 10.9 " ) +
 std::string( " 11.0 11.1 11.2 11.3 11.4 11.5 11.6 11.7 11.8 11.9 " ) +
 std::string( " 12.0 12.1 12.2 12.3 12.4 12.5 12.6 12.7 12.8 12.9 " ) +
 std::string( " 13.0 13.1 13.2 13.3 13.4 13.5 13.6 13.7 13.8 " ) + // Card12a-nus
 std::string( " 14.0 14.1 14.2 14.3 14.4 14.5 14.6 14.7 14.8 14.9" ) +
 std::string( " 15.0 15.1 15.2 15.3 15.4 15.5 15.6 15.7 15.8 15.9" ) +
 std::string( " 16.0 16.1 16.2 16.3 16.4 16.5 16.6 16.7 16.8 16.9" ) +
 std::string( " 17.0 17.1 17.2 17.3 17.4 17.5 17.6 17.7 17.8 17.9" ) +
 std::string( " 18.0 18.1 18.2 18.3 18.4 18.5 18.6 18.7 18.8 18.9" ) +
 std::string( " 19.0 19.1 19.2 19.3 19.4 19.5 19.6 19.7 19.8 19.9" ) +
 std::string( " 20.0 20.1 20.2 20.3 20.4 20.5 20.6 20.7 20.8" ) + // Card12a-fis
 std::string( " 21.0 21.1 21.2 21.3 21.4 21.5 21.6 21.7 21.8 21.9" ) +
 std::string( " 22.0 22.1 22.2 22.3 22.4 22.5 22.6 22.7 22.8 22.9" ) +
 std::string( " 23.0 23.1 23.2 23.3 23.4 23.5 23.6 23.7 23.8 23.9" ) +
 std::string( " 24.0 24.1 24.2 24.3 24.4 24.5 24.6 24.7 24.8 24.9" ) +
 std::string( " 25.0 25.1 25.2 25.3 25.4 25.5 25.6 25.7 25.8 25.9" ) +
 std::string( " 26.0 26.1 26.2 26.3 26.4 26.5 26.6 26.7 26.8 26.9" ) +
 std::string( " 27.0 27.1 27.2 27.3 27.4 27.5 27.6 27.7 27.8 /\n" ) + // Card12a-xtr
 std::string( " 1 1 3 /\n" ) + // Card12b-1
 std::string( " 100.0 100.1 100.2 /\n" ) + // Card12c-1
 std::string( " 2 1 4 /\n" ) + // Card12b-2
 std::string( " 101.0 101.1 101.2 101.3 /\n" ) + // Card12c-2
 std::string( " 3 2 5 /\n" ) + // Card12b-3
 std::string( " 102.0 102.1 102.2 102.3 /\n" ) + // Card12c-3
 std::string( " 4 3 6 /\n" ) + // Card12b-4
 std::string( " 103.0 103.1 103.2 103.3 /\n" ) + // Card12c-4
 std::string( " 5 4 7 /\n" ) + // Card12b-5
 std::string( " 104.0 104.1 104.2 104.3 /\n" ) + // Card12c-5
 std::string( " 6 5 8 /\n" ) + // Card12b-6
 std::string( " 105.0 105.1 105.2 105.3 /\n" ) + // Card12c-6
 std::string( " 7 6 9 /\n" ) + // Card12b-7
 std::string( " 106.0 106.1 106.2 106.3 /\n" ) + // Card12c-7
 std::string( " 8 7 10 /\n" ) + // Card12b-8
 std::string( " 107.0 107.1 107.2 107.3 /\n" ) + // Card12c-8
 std::string( " 9 8 11 /\n" ) + // Card12b-9
 std::string( " 108.0 108.1 108.2 108.3 /\n" ) + // Card12c-9
 std::string( " 10 9 12 /\n" ) + // Card12b-10
 std::string( " 109.0 109.1 109.2 109.3 /\n" ) + // Card12c-10
 std::string( " 11 10 13 /\n" ) + // Card12b-11
 std::string( " 110.0 110.1 110.2 110.3 /\n" ) + // Card12c-11
 std::string( " 12 11 14 /\n" ) + // Card12b-12
 std::string( " 111.0 111.1 111.2 111.3 /\n" ) + // Card12c-12
 std::string( " 13 12 15 /\n" ) + // Card12b-13
 std::string( " 112.0 112.1 112.2 112.3 /\n" ) + // Card12c-13
 std::string( " 14 13 16 /\n" ) + // Card12b-14
 std::string( " 113.0 113.1 113.2 113.3 /\n" ) + // Card12c-14
 std::string( " 15 14 17 /\n" ) + // Card12b-15
 std::string( " 114.0 114.1 114.2 114.3 /\n" ) + // Card12c-15
 std::string( " 16 15 18 /\n" ) + // Card12b-16
 std::string( " 115.0 115.1 115.2 115.3 /\n" ) + // Card12c-16
 std::string( " 17 16 19 /\n" ) + // Card12b-17
 std::string( " 116.0 116.1 116.2 116.3 /\n" ) + // Card12c-17
 std::string( " 18 17 20 /\n" ) + // Card12b-18
 std::string( " 117.0 117.1 117.2 117.3 /\n" ) + // Card12c-18
 std::string( " 19 18 21 /\n" ) + // Card12b-19
 std::string( " 118.0 118.1 118.2 118.3 /\n" ) + // Card12c-19
 std::string( " 20 19 22 /\n" ) + // Card12b-20
 std::string( " 119.0 119.1 119.2 119.3 /\n" ) + // Card12c-20
 std::string( " 21 20 23 /\n" ) + // Card12b-21
 std::string( " 120.0 120.1 120.2 120.3 /\n" ) + // Card12c-21
 std::string( " 22 21 24 /\n" ) + // Card12b-22
 std::string( " 121.0 121.1 121.2 121.3 /\n" ) + // Card12c-22
 std::string( " 23 22 25 /\n" ) + // Card12b-23
 std::string( " 122.0 122.1 122.2 122.3 /\n" ) + // Card12c-23
 std::string( " 24 23 26 /\n" ) + // Card12b-24
 std::string( " 123.0 123.1 123.2 123.3 /\n" ) + // Card12c-24
 std::string( " 25 24 27 /\n" ) + // Card12b-25
 std::string( " 124.0 124.1 124.2 124.3 /\n" ) + // Card12c-25
 std::string( " 26 25 28 /\n" ) + // Card12b-26
 std::string( " 125.0 125.1 125.2 125.3 /\n" ) + // Card12c-26
 std::string( " 27 26 29 /\n" ) + // Card12b-27
 std::string( " 126.0 126.1 126.2 126.3 /\n" ) + // Card12c-27
 std::string( " 28 27 30 /\n" ) + // Card12b-28
 std::string( " 127.0 127.1 127.2 127.3 /\n" ) + // Card12c-28
 std::string( " 29 28 31 /\n" ) + // Card12b-29
 std::string( " 128.0 128.1 128.2 128.3 /\n" ) + // Card12c-29
 std::string( " 30 29 32 /\n" ) + // Card12b-30
 std::string( " 129.0 129.1 129.2 129.3 /\n" ) + // Card12c-30
 std::string( " 31 30 33 /\n" ) + // Card12b-31
 std::string( " 130.0 130.1 130.2 130.3 /\n" ) + // Card12c-31
 std::string( " 32 31 34 /\n" ) + // Card12b-32
 std::string( " 131.0 131.1 131.2 131.3 /\n" ) + // Card12c-32
 std::string( " 33 32 35 /\n" ) + // Card12b-33
 std::string( " 132.0 132.1 132.2 132.3 /\n" ) + // Card12c-33
 std::string( " 34 33 36 /\n" ) + // Card12b-34
 std::string( " 133.0 133.1 133.2 133.3 /\n" ) + // Card12c-34
 std::string( " 35 34 37 /\n" ) + // Card12b-35
 std::string( " 134.0 134.1 134.2 134.3 /\n" ) + // Card12c-35
 std::string( " 36 35 38 /\n" ) + // Card12b-36
 std::string( " 135.0 135.1 135.2 135.3 /\n" ) + // Card12c-36
 std::string( " 37 36 39 /\n" ) + // Card12b-37
 std::string( " 136.0 136.1 136.2 136.3 /\n" ) + // Card12c-37
 std::string( " 38 37 40 /\n" ) + // Card12b-38
 std::string( " 137.0 137.1 137.2 137.3 /\n" ) + // Card12c-38
 std::string( " 39 38 41 /\n" ) + // Card12b-39
 std::string( " 138.0 138.1 138.2 138.3 /\n" ) + // Card12c-39
 std::string( " 40 39 42 /\n" ) + // Card12b-40
 std::string( " 139.0 139.1 139.2 139.3 /\n" ) + // Card12c-40
 std::string( " 41 40 43 /\n" ) + // Card12b-41
 std::string( " 140.0 140.1 140.2 140.3 /\n" ) + // Card12c-41
 std::string( " 42 41 44 /\n" ) + // Card12b-42
 std::string( " 141.0 141.1 141.2 141.3 /\n" ) + // Card12c-42
 std::string( " 43 42 45 /\n" ) + // Card12b-43
 std::string( " 142.0 142.1 142.2 142.3 /\n" ) + // Card12c-43
 std::string( " 44 43 46 /\n" ) + // Card12b-44
 std::string( " 143.0 143.1 143.2 143.3 /\n" ) + // Card12c-44
 std::string( " 45 44 47 /\n" ) + // Card12b-45
 std::string( " 144.0 144.1 144.2 144.3 /\n" ) + // Card12c-45
 std::string( " 46 45 48 /\n" ) + // Card12b-46
 std::string( " 145.0 145.1 145.2 145.3 /\n" ) + // Card12c-46
 std::string( " 47 46 49 /\n" ) + // Card12b-47
 std::string( " 146.0 146.1 146.2 146.3 /\n" ) + // Card12c-47
 std::string( " 48 47 50 /\n" ) + // Card12b-48
 std::string( " 147.0 147.1 147.2 147.3 /\n" ) + // Card12c-48
 std::string( " 49 48 51 /\n" ) + // Card12b-49
 std::string( " 148.0 148.1 148.2 148.3 /\n" ) + // Card12c-49
 std::string( " 50 49 52 /\n" ) + // Card12b-50
 std::string( " 149.0 149.1 149.2 149.3 /\n" ) + // Card12c-50
 std::string( " 51 50 53 /\n" ) + // Card12b-51
 std::string( " 150.0 150.1 150.2 150.3 /\n" ) + // Card12c-51
 std::string( " 52 51 54 /\n" ) + // Card12b-52
 std::string( " 151.0 151.1 151.2 151.3 /\n" ) + // Card12c-52
 std::string( " 53 52 55 /\n" ) + // Card12b-53
 std::string( " 152.0 152.1 152.2 153.3 /\n" ) + // Card12c-53
 std::string( " 54 53 56 /\n" ) + // Card12b-54
 std::string( " 153.0 153.1 153.2 153.3 /\n" ) + // Card12c-54
 std::string( " 55 54 57 /\n" ) + // Card12b-55
 std::string( " 154.0 154.1 154.2 154.3 /\n" ) + // Card12c-55
 std::string( " 56 55 58 /\n" ) + // Card12b-56
 std::string( " 155.0 155.1 155.2 155.3 /\n" ) + // Card12c-56
 std::string( " 57 56 59 /\n" ) + // Card12b-57
 std::string( " 156.0 156.1 156.2 156.3 /\n" ) + // Card12c-57
 std::string( " 58 57 60 /\n" ) + // Card12b-58
 std::string( " 157.0 157.1 157.2 157.3 /\n" ) + // Card12c-58
 std::string( " 59 58 61 /\n" ) + // Card12b-59
 std::string( " 158.0 158.1 158.2 158.3 /\n" ) + // Card12c-59
 std::string( " 60 59 62 /\n" ) + // Card12b-60
 std::string( " 159.0 159.1 159.2 159.3 /\n" ) + // Card12c-60
 std::string( " 61 60 63 /\n" ) + // Card12b-61
 std::string( " 160.0 160.1 160.2 160.3 /\n" ) + // Card12c-61
 std::string( " 62 61 64 /\n" ) + // Card12b-62
 std::string( " 161.0 161.1 161.2 161.3 /\n" ) + // Card12c-62
 std::string( " 63 62 65 /\n" ) + // Card12b-63
 std::string( " 162.0 162.1 162.2 162.3 /\n" ) + // Card12c-63
 std::string( " 64 63 66 /\n" ) + // Card12b-64
 std::string( " 163.0 163.1 163.2 163.3 /\n" ) + // Card12c-64
 std::string( " 65 64 67 /\n" ) + // Card12b-65
 std::string( " 164.0 164.1 164.2 164.3 /\n" ) + // Card12c-65
 std::string( " 66 65 68 /\n" ) + // Card12b-66
 std::string( " 165.0 165.1 165.2 165.3 /\n" ) + // Card12c-66
 std::string( " 67 66 69 /\n" ) + // Card12b-67
 std::string( " 166.0 166.1 166.2 166.3 /\n" ) + // Card12c-67
 std::string( " 68 67 69 /\n" ) + // Card12b-68
 std::string( " 167.0 167.1 167.2 /\n" ) + // Card12c-68
 std::string( " 69 68 69 /\n" ) + // Card12b-69
 std::string( " 168.0 168.1 /\n" ) // Card12c-69
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "the values can be verified" ){
        POWR powr( iss );

        REQUIRE( 50 == powr.card1.ngendf.value );
        REQUIRE( 60 == powr.card1.nout.value );

        REQUIRE( 3 == powr.card2.lib.value );
        REQUIRE( 0 == powr.card2.iprint.value );
        REQUIRE( 0 == powr.card2.iclaps.value );

        REQUIRE( 1 == std::experimental::get<2>( powr.lib ).card3.nlib.value );
        REQUIRE( 20000201 == std::experimental::get<2>( powr.lib ).card3.idat.value );
        REQUIRE( 2 == std::experimental::get<2>( powr.lib ).card3.newmat.value );
        REQUIRE( 0 == std::experimental::get<2>( powr.lib ).card3.iopt.value );
        REQUIRE( 0 == std::experimental::get<2>( powr.lib ).card3.mode.value );
        REQUIRE( 2 == std::experimental::get<2>( powr.lib ).card3.if5.value );
        REQUIRE( 1 == std::experimental::get<2>( powr.lib ).card3.if4.value );

        REQUIRE( 1200 == std::experimental::get<2>( powr.lib ).card4->mat.value.at(0) );
        REQUIRE( 9439 == std::experimental::get<2>( powr.lib ).card4->mat.value.at(1) );

        REQUIRE( 3 == std::experimental::get<2>( powr.lib ).card5List.at(0).nina.value );
        REQUIRE( 2 == std::experimental::get<2>( powr.lib ).card5List.at(0).ntemp.value );
        REQUIRE( 3 == std::experimental::get<2>( powr.lib ).card5List.at(0).nsigz.value );
        REQUIRE( Approx( 4.0 ) ==
                          std::experimental::get<2>( powr.lib ).card5List.at(0).sgref.value );
        REQUIRE( 1 ==
                  std::experimental::get<2>( powr.lib ).card5List.at(0).nina03->first.value );
        REQUIRE( Approx( 5.0 ) ==
                 std::experimental::get<2>( powr.lib ).card5List.at(0).nina03->second.value );
        REQUIRE( 6 == std::get<0>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(0).ntapea0 ) ).value );
        REQUIRE( 7 == std::get<1>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(0).ntapea0 ) ).value );
        REQUIRE( 0 == std::get<2>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(0).ntapea0 ) ).value );
        REQUIRE( 0 == std::get<3>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(0).ntapea0 ) ).value );
        REQUIRE( 8 ==
                   std::experimental::get<2>( powr.lib ).card5List.at(0).mode0->first.value );
        REQUIRE( 9 ==
                  std::experimental::get<2>( powr.lib ).card5List.at(0).mode0->second.value );

        REQUIRE( 1 == std::experimental::get<2>( powr.lib ).card5List.at(1).nina.value );
        REQUIRE( 0 == std::experimental::get<2>( powr.lib ).card5List.at(1).ntemp.value );
        REQUIRE( 0 == std::experimental::get<2>( powr.lib ).card5List.at(1).nsigz.value );
        REQUIRE( Approx( 1.0 ) ==
                          std::experimental::get<2>( powr.lib ).card5List.at(1).sgref.value );
        REQUIRE( 2 == std::get<0>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(1).ntapea0 ) ).value );
        REQUIRE( 3 == std::get<1>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(1).ntapea0 ) ).value );
        REQUIRE( 0 == std::get<2>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(1).ntapea0 ) ).value );
        REQUIRE( 1 == std::get<3>( *( std::experimental::get<2>( powr.lib
                                          ).card5List.at(1).ntapea0 ) ).value );
        REQUIRE( 4 ==
                   std::experimental::get<2>( powr.lib ).card5List.at(1).mode0->first.value );
        REQUIRE( 5 ==
                  std::experimental::get<2>( powr.lib ).card5List.at(1).mode0->second.value );

        REQUIRE( 2 == std::get<0>( *( std::experimental::get<2>( powr.lib ).card678List )
                                                                 ).ntis.value );
        REQUIRE( 1 == std::get<0>( *( std::experimental::get<2>( powr.lib ).card678List )
                                                                 ).nfis.value );

        REQUIRE( 9439 == std::get<1>( *( std::experimental::get<2>( powr.lib ).card678List )
                                                         ).identb.value.at(0) );

        REQUIRE( 1200 == std::get<2>( *( std::experimental::get<2>( powr.lib ).card678List )
                                                         ).at(0).identa.value );
        REQUIRE( Approx( 0.5 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                          ).card678List ) ).at(0).decay.value );
        REQUIRE( Approx( 0.0 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                    ).card678List ) ).at(0).yield.value.at(0) );
        REQUIRE( Approx( 0.0 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                    ).card678List ) ).at(0).yield.value.at(1) );
        REQUIRE( Approx( 0.0 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                    ).card678List ) ).at(0).yield.value.at(2) );

        REQUIRE( 9439 == std::get<2>( *( std::experimental::get<2>( powr.lib ).card678List )
                                                         ).at(1).identa.value );
        REQUIRE( Approx( 1.0 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                          ).card678List ) ).at(1).decay.value );
        REQUIRE( Approx( 0.2 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                    ).card678List ) ).at(1).yield.value.at(0) );
        REQUIRE( Approx( 0.3 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                    ).card678List ) ).at(1).yield.value.at(1) );
        REQUIRE( Approx( 0.5 ) == std::get<2>( *( std::experimental::get<2>( powr.lib
                                    ).card678List ) ).at(1).yield.value.at(2) );

        REQUIRE( Approx( 1200.0 ) == std::experimental::get<2>( powr.lib ).card9List->
                                                               at(0).aw.value );
        REQUIRE( 0 == std::experimental::get<2>( powr.lib ).card9List->at(0).indfis.value );
        REQUIRE( 1 == std::experimental::get<2>( powr.lib ).card9List->at(0).ntemp.value );

        for( size_t i = 0; i < 13; i++ ){
          double d( 0.1*i );
          REQUIRE( Approx( d ) == std::experimental::get<2>( powr.lib ).card10List.at(0)->
                                                           lambda.value.at(i) );
          double e( 0.1*i + 2.0 );
          REQUIRE( Approx( e ) == std::experimental::get<2>( powr.lib ).card11List.at(0)->
                                                      first.resnu.value.at(i) );
          double f( 0.1*i + 4.0 );
          REQUIRE(Approx( f ) == std::experimental::get<2>( powr.lib ).card11List.at(0)->
                                                        second.tot.value.at(i));
        }

        REQUIRE( Approx( 100.0 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                                               first.aw.value );
        REQUIRE( 101.0*dimwits::kelvin == 
                  std::experimental::get<2>( powr.lib ).card12List->at(0)->first.temp.value );

        for( size_t i = 0; i < 69; i++ ){
          double d( 0.1*i );
          REQUIRE(Approx( d ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                                         first.fpa.value.at(i));
          double e( 0.1*i + 7.0 );
          REQUIRE( Approx( e ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                                 second.first.nus.value.at(i) );
          double f( 0.1*i + 14.0 );
          REQUIRE( Approx( f ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                                 second.first.fis.value.at(i) );
          double g( 0.1*i + 21.0 );
          REQUIRE( Approx( g ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                                 second.first.xtr.value.at(i) );
        }

        REQUIRE( 1 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                           second.second.at(0).first.ia.value );
        REQUIRE( 1 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                           second.second.at(0).first.l1.value );
        REQUIRE( 3 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                           second.second.at(0).first.l2.value );

        REQUIRE( Approx( 100.0 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                 second.second.at(0).second->scat.value.at(0) );
        REQUIRE( Approx( 100.1 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                 second.second.at(0).second->scat.value.at(1) );
        REQUIRE( Approx( 100.2 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                 second.second.at(0).second->scat.value.at(2) );

        for( int i = 1; i < 67; i++ ){
          REQUIRE( i+1 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                           second.second.at(i).first.ia.value );
          REQUIRE( i == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                           second.second.at(i).first.l1.value );
          REQUIRE( i+3 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                           second.second.at(i).first.l2.value );
        }

        REQUIRE( 68 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                          second.second.at(67).first.ia.value );
        REQUIRE( 67 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                          second.second.at(67).first.l1.value );
        REQUIRE( 69 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                          second.second.at(67).first.l2.value );

        REQUIRE( Approx( 167.0 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                second.second.at(67).second->scat.value.at(0) );
        REQUIRE( Approx( 167.1 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                second.second.at(67).second->scat.value.at(1) );
        REQUIRE( Approx( 167.2 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                second.second.at(67).second->scat.value.at(2) );

        REQUIRE( 69 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                          second.second.at(68).first.ia.value );
        REQUIRE( 68 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                          second.second.at(68).first.l1.value );
        REQUIRE( 69 == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                          second.second.at(68).first.l2.value );

        REQUIRE( Approx( 168.0 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                second.second.at(68).second->scat.value.at(0) );
        REQUIRE( Approx( 168.1 ) == std::experimental::get<2>( powr.lib ).card12List->at(0)->
                                second.second.at(68).second->scat.value.at(1) );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "no input is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR( iss ) );
      }
    }

    WHEN( "too many temperatures are provided for lib=2" ){
      std::string inp(
 std::string( " 95 99 /\n" ) + // Card1
 std::string( " 2 1 0 /\n" ) + // Card2
 std::string( " 2345 3.14 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 2345 3.10 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 2345 3.11 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 2345 3.12 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 2345 3.13 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 2345 3.15 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 2345 3.16 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 2345 3.17 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 0 /" ) // Terminating Card3
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR( iss ) );
      }
    } // WHEN

    WHEN( "invalid value is provided" ){
      std::string inp(
 std::string( " 95 99 /\n" ) + // Card1
 std::string( " 2 1 2 /\n" ) + // Card2
 std::string( " 2345 3.14 'hollerith' /\n" ) + // Card3
 std::string( " 1 2 3 /\n" ) + // Card4
 std::string( " 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 /\n" ) + // Card5
 std::string( " 0 /" )
      );

      iRecordStream<char> iss{ std::istringstream{ inp } };

      THEN( "an exception is thrown" ){
        REQUIRE_THROWS( POWR( iss ) );
      }

    } // WHEN
  } // GIVEN
} // SCENARIO
