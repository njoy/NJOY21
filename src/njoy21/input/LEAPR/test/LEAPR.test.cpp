#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "LEAPR input",
  "[LEAPR]" ){
  auto InverseAngstrom =  dimwits::pow( 1.0 * dimwits::angstrom, dimwits::Ratio<-1> );
  GIVEN( "valid LEAPR input, multiple temperatures loops" ){
    WHEN( "no sec. scatterer (card6 nss=0), temp specific inputs (Card11-18)" ){
      iRecordStream<char> iss( std::istringstream(
        "20\n" 					// Card1
        "'graphite, endf model (extended)'\n"	// Card2
        "2 0 101\n"  				// Card3
        "31 6012.0 1 1\n" 			// Card4
        "11.898 4.7392 1 1 1 1\n" 		// Card5
        "0/ \n"					// Card6
        "3 5 1/\n"				// Card7
        "2.5e-1 7.5e-1 1.0/\n"			// Card8
        "0.0 0.2 0.4 0.6 0.8/\n"		// Card9
        "293/\n"				// Card10 --
	".03 4\n"				// Card11  |
	"1.0 2.0 3.0 4.0\n" 			// Card12  |
	"0.0192 0.0 0.4904\n" 			// Card13  |
	"2\n"		 			// Card14  |- Temp Loop 1
	"0.205 0.436\n"	 			// Card15  |
	"0.163467 0.326933\n"	 		// Card16  |
	"2 0.001\n"		 		// Card17  |
	"1.5 2.0\n"		 		// Card18 --
        "300/\n"				// Card10 --
	".02 3\n"				// Card11  |
	"2.0 4.0 6.0\n" 			// Card12  |- Temp Loop 2
	"0.2 0.0 0.5\n" 			// Card13  |
	"0\n"  					// Card14, no Card15 or Card16
	"3 0.002\n"		 		// Card17  |
	"2.0 2.5 3.0\n"		 		// Card18 --
	"'test run for njoy leapr\n"		// Card20
	" where this fun comment spans\n"	//
	" multiple lines.'\n"			//
	"/ "

      ) );
      THEN( "all cards have the correct values" ){
        LEAPR leapr( iss );
        REQUIRE( leapr.card1.nout.value == 20 );

        REQUIRE( leapr.card2.title.value == "graphite, endf model (extended)" );

        REQUIRE( leapr.card3.ntempr.value == 2   );
        REQUIRE( leapr.card3.iprint.value == 0   );
        REQUIRE( leapr.card3.nphon.value  == 101 );

        REQUIRE( leapr.card4.mat.value   == 31     );
        REQUIRE( leapr.card4.za.value    == 6012.0 );
        REQUIRE( leapr.card4.isabt.value == 1      );
        REQUIRE( leapr.card4.ilog.value  == 1      );
      
        REQUIRE( leapr.card5.awr.value   == 11.898 );
        REQUIRE( leapr.card5.spr.value   == 4.7392 * dimwits::barn );
        REQUIRE( leapr.card5.npr.value   == 1 );
        REQUIRE( leapr.card5.iel.value   == 1 );
        REQUIRE( leapr.card5.ncold.value == 1 );
        REQUIRE( leapr.card5.nsk.value   == 1 );
      
        REQUIRE( leapr.card6.nss.value == 0   );
	REQUIRE( not leapr.card6.controlTuple );

        REQUIRE( leapr.card7.nalpha.value == 3 );
        REQUIRE( leapr.card7.nbeta.value  == 5 );
        REQUIRE( leapr.card7.lat.value    == 1 );

	std::vector<double> refAlphas = { 0.25, 0.75, 1.0 };
	std::vector<double> refBetas  = { 0.0, 0.2, 0.4, 0.6, 0.8 };

	REQUIRE( leapr.card8.alpha.value.size() == 3 );
	REQUIRE( leapr.card9.beta.value.size()  == 5 );
	
	REQUIRE( leapr.card8.alpha.value == refAlphas );
	REQUIRE( leapr.card9.beta.value  == refBetas  );

	REQUIRE( leapr.tempLoop.size() == 2 );
	const auto& loop1 = leapr.tempLoop[0];
	{
  	  const auto& card10 = std::get<0>( loop1 );
	  const auto& card11 = std::get<1>( loop1 );
	  const auto& card12 = std::get<2>( loop1 );
	  const auto& card13 = std::get<3>( loop1 );
	  const auto& card14 = std::get<4>( loop1 );
	  const auto& oscillatorTuple = std::get<5>( loop1 );
	  const auto& card15 = std::get<0>( *oscillatorTuple );
	  const auto& card16 = std::get<1>( *oscillatorTuple );
	  const auto& pairCorrelTuple = std::get<6>( loop1 );
	  const auto& card17 = std::get<0>( *pairCorrelTuple );
	  const auto& card18 = std::get<1>( *pairCorrelTuple );
	  const auto& card19 = std::get<2>( *pairCorrelTuple );

	  REQUIRE( card10.temp.value  == 293.0 * dimwits::kelvin );
	  REQUIRE( card11.delta.value == 0.03 * dimwits::electronVolts );
	  REQUIRE( card11.ni.value    == 4 );
	  std::vector<double> refRho = { 1.0, 2.0, 3.0, 4.0 };
	  REQUIRE( card12.rho.value   == refRho ); 
	  REQUIRE( card13.twt.value   == 0.0192 );
	  REQUIRE( card13.c.value     == 0.0	);
	  REQUIRE( card13.tbeta.value == 0.4904 );
	  REQUIRE( card14.nd.value    == 2 	);
	  std::vector< dimwits::Quantity< dimwits::ElectronVolts > > refOes = {
            0.205 * dimwits::electronVolts, 0.436 * dimwits::electronVolts };
	  REQUIRE( card15->oe.value    == refOes	);
	  std::vector< double > refOws = { 0.163467, 0.326933 };
	  REQUIRE( card16->ow.value    == refOws );
	  REQUIRE( card17->nka.value   == 2      );
 	  REQUIRE( card17->dka.value   == 0.001 * InverseAngstrom );
	  std::vector< decltype( InverseAngstrom ) > refSkappas{ 
	    1.5 * InverseAngstrom, 
	    2.0 * InverseAngstrom };
	  REQUIRE( card18->skappa.value == refSkappas );
	  REQUIRE( not card19 );
	 
        }
	const auto& loop2 = leapr.tempLoop[1];
	{
  	  const auto& card10 = std::get<0>( loop2 );
	  const auto& card11 = std::get<1>( loop2 );
	  const auto& card12 = std::get<2>( loop2 );
	  const auto& card13 = std::get<3>( loop2 );
	  const auto& card14 = std::get<4>( loop2 );
	  const auto& oscillatorTuple = std::get<5>( loop2 );
	  const auto& pairCorrelTuple = std::get<6>( loop2 );
	  const auto& card17 = std::get<0>( *pairCorrelTuple );
	  const auto& card18 = std::get<1>( *pairCorrelTuple );
	  const auto& card19 = std::get<2>( *pairCorrelTuple );

	  REQUIRE( card10.temp.value  == 300.0 * dimwits::kelvin );
	  REQUIRE( card11.delta.value == 0.02 * dimwits::electronVolts );
	  REQUIRE( card11.ni.value    == 3 	);
	  std::vector<double> refRho = { 2.0, 4.0, 6.0 };
	  REQUIRE( card12.rho.value   == refRho	); 
	  REQUIRE( card13.twt.value   == 0.2 	);
	  REQUIRE( card13.c.value     == 0.0 	);
	  REQUIRE( card13.tbeta.value == 0.5 	);
	  REQUIRE( card14.nd.value    == 0 	);
	  REQUIRE( not oscillatorTuple );
	  REQUIRE( card17->nka.value  == 3      );
	  REQUIRE( card17->dka.value  == 0.002 * InverseAngstrom );
	  std::vector< decltype( InverseAngstrom ) > refSkappas{ 
	    2.0 * InverseAngstrom, 
	    2.5 * InverseAngstrom, 
	    3.0 * InverseAngstrom };
	  REQUIRE( card18->skappa.value == refSkappas );
	  REQUIRE( not card19 );
        }

        std::string refCard20_0 = "test run for njoy leapr where this "
		                  "fun comment spans multiple lines.";
	const auto& card20_0 = leapr.card20List[0];
	REQUIRE( *(card20_0.comment.value) == refCard20_0 );

      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO
