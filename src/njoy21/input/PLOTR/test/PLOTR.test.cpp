#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

std::string sCard0( "23 /\n" );
std::string sCard1( "1 1 0.1 1 /\n" );
std::string sCard2_1( "1 7 1.1 2.1 1.2 1.3 5.0 5.1 0.1 /\n" );
std::string sCard3_1( "PLOTR Card3 title for testing" );
std::string sCard3a_1( "PLOTR Card3a title for testing" );
std::string sCard4_1( "1 0 2 2 10.0 10.0 /\n" );
std::string sCard5_1( "0.1 100.1 1.0 /\n" );
std::string sCard5a_1( "ENERGY (EV) TEST" );
std::string sCard6_1( "0.2 100.2 2.0 /\n" );
std::string sCard6a_1( "CROSS SECTION (BARNS) TEST" );
// No card 7 or 7a.
std::string sCard8_1( "2 23 9439 5 90 25.5 1 /\n" ); // No NTP and NKH with MF=5
std::string sCard9_1( "5 1 1 1 1 0 /\n" );
std::string sCard10_1( "Title for curve tag or legend block 1" );
std::string sCard10a_1( "20.0 20.0 25.0 /\n" );
// No card 11.
// No card 12.
// No card 13.
std::string sCard2_2( "99 /\n" );

// 3-D input.
std::string sCard4_2( "-1 1 2 0 /\n" );
std::string sCard7_2( "-10.0 10.0 0.001 /\n" );
std::string sCard7a_2( "ALTERNATE AXIS TITLE (UNITS) TEST" );

// Freeform input
std::string sCard4_3( "1 /\n" );
std::string sCard5_3( " /\n" );
std::string sCard5a_3( " /\n" );
std::string sCard6_3( " /\n" );
std::string sCard6a_3( " /\n" );
// No card 7 or 7a.
std::string sCard8_3( " 0 /\n" );
// No card 10 or 10a or 11.
std::string sCard12_3( " 0 /\n" );
std::string sCard13_3_1( " 1.0 2.0 1.5 2.5 0.5 1.5 /\n" );
std::string sCard13_3_2( " 5.0 5.0 0 0 0 0 /\n" );
std::string sCard13_3_3( " 20.1 21.2 10.0 30.0 10.0 25.0 /\n" );
std::string sCard13_3_4( " /\n" );

SCENARIO( "Parsing valid PLOTR input" ){
  WHEN( "reading in a very generic input" ){
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' /\n"
      + sCard4_1
      + sCard5_1
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard8_1
      + sCard9_1
      + "'" + sCard10_1 + "' /\n"
      + sCard10a_1
      + sCard2_2
    ) );

    PLOTR plotr( iss );

    THEN( "the Card0 input values can be verified: 23" ){
      REQUIRE( 23 == plotr.card0.nplt.value );
      REQUIRE( 0  == plotr.card0.nplt0.value );
    }
    THEN( "the Card1 input values can be verified: 1 1 0.1 1" ){
      REQUIRE( 1 == plotr.card1.lori.value );
      REQUIRE( 1 == plotr.card1.istyle.value );
      REQUIRE( Approx( 0.1 ) == plotr.card1.size.value );
      REQUIRE( 1 == plotr.card1.ipcol.value );
    }
    THEN( "the curves variable should have a length of 1" ){
      REQUIRE( 1 == plotr.curves.size() );
    }
    THEN(
    "the Card2 input values can be verified: 1 7 1.1 2.1 1.2 1.3 5.0 5.1 0.1" ){
      REQUIRE( 1 == plotr.curves[0].first.iplot.value );
      REQUIRE( 7 == plotr.curves[0].first.iwcol.value );
      REQUIRE( Approx( 1.1 ) == plotr.curves[0].first.factx.value );
      REQUIRE( Approx( 2.1 ) == plotr.curves[0].first.facty.value );
      REQUIRE( Approx( 1.2 ) == plotr.curves[0].first.xll.value );
      REQUIRE( Approx( 1.3 ) == plotr.curves[0].first.yll.value );
      REQUIRE( Approx( 5.0 ) == plotr.curves[0].first.ww.value );
      REQUIRE( Approx( 5.1 ) == plotr.curves[0].first.wh.value );
      REQUIRE( Approx( 0.1 ) == plotr.curves[0].first.wr.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3_1 == plotr.curves[0].second.plot->card3.title.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3a_1 == plotr.curves[0].second.plot->card3a.title.value );
    }
    THEN( "the Card4 input values can be verified: 1 0 2 1 10.0 10.0" ){
      REQUIRE( 1 == plotr.curves[0].second.plot->card4.itype.value );
      REQUIRE( 0 == plotr.curves[0].second.plot->card4.jtype.value );
      REQUIRE( 2 == plotr.curves[0].second.plot->card4.igrid.value );
      REQUIRE( 2 == plotr.curves[0].second.plot->card4.ileg.value );
      REQUIRE( Approx( 10.0 ) == 
               *( plotr.curves[0].second.plot->card4.xtag.value ) );
      REQUIRE( Approx( 10.0 ) == 
               *( plotr.curves[0].second.plot->card4.ytag.value ) );
    }

    THEN( "the Card5 input values can be verified: 0.1 100.1 1.0" ){
      REQUIRE( Approx( 0.1 ) == plotr.curves[0].second.plot->card5.el.value );
      REQUIRE( Approx( 100.1 ) == plotr.curves[0].second.plot->card5.eh.value );
      REQUIRE( Approx( 1.0 ) == 
               plotr.curves[0].second.plot->card5.xstep.value );
    }
    THEN( "the Card5a input values can be verified" ){
      REQUIRE( sCard5a_1 == plotr.curves[0].second.plot->card5a.xlabl.value );
    }

    THEN( "the Card6 input values can be verified: 0.2 100.2 2.0" ){
      REQUIRE( Approx( 0.2 ) == plotr.curves[0].second.plot->card6.yl.value );
      REQUIRE( Approx( 100.2 ) == plotr.curves[0].second.plot->card6.yh.value );
      REQUIRE( Approx( 2.0 ) == 
               plotr.curves[0].second.plot->card6.ystep.value );
    }
    THEN( "the Card6a input values can be verified" ){
      REQUIRE( sCard6a_1 == plotr.curves[0].second.plot->card6a.ylabl.value );
    }

    THEN( "Card7 is unused" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card7 );
    }

    THEN( "the Card8 input values can be verified: 1 23 9439 3 90 25.5 1" ){
      REQUIRE( 2 == plotr.curves[0].second.card8.iverf.value );
      REQUIRE( 23 == *( plotr.curves[0].second.card8.nin.value ) );
      REQUIRE( 9439 == *( plotr.curves[0].second.card8.matd.value ) );
      REQUIRE( 5 == *( plotr.curves[0].second.card8.mfd.value ) );
      REQUIRE( 90 == *( plotr.curves[0].second.card8.mtd.value ) );
      REQUIRE( 25.5 * dimwits::kelvin == 
               *( plotr.curves[0].second.card8.temper.value ) );
      REQUIRE( 1 == *( plotr.curves[0].second.card8.nth.value ) );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.ntpnkh );
    }

    THEN( "the Card9 input values can be verified: 5 1 1 1 1 0" ){
      REQUIRE( 5 == plotr.curves[0].second.card9.icon.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.isym.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.idash.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.iccol.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.ithick.value );
      REQUIRE( 0 == plotr.curves[0].second.card9.ishade.value );
    }

    THEN( "the Card10 input values can be verified" ){
      REQUIRE( sCard10_1 == plotr.curves[0].second.card10->aleg.value );
    }

    THEN( "the Card10a input values can be verified: 20.0 20.0 25.0" ){
      REQUIRE( Approx( 20.0 ) == plotr.curves[0].second.card10a->xtag.value );
      REQUIRE( Approx( 20.0 ) == plotr.curves[0].second.card10a->ytag.value );
      REQUIRE( Approx( 25.0 ) == plotr.curves[0].second.card10a->xpoint.value );
    }

    THEN( "the remaining cards are empty" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.card11 );
      REQUIRE( std::nullopt == plotr.curves[0].second.freeform );
    }
  }//WHEN
  WHEN( "reading in an input with 3-D axes" ){
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' /\n"
      + sCard4_2 // -1 1 2 0
      + sCard5_1
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard7_2 // -10.0 10.0 0.001
      + "'" + sCard7a_2 + "' /\n" // ALTERNATE AXIS TITLE (UNITS) TEST
      + sCard8_1
      + sCard9_1
      + " /\n" // Card 11 - All default values (15,-15,15; 2.5,6.5,2.5)
      + sCard2_2
    ) );

    PLOTR plotr( iss );

    THEN( "the Card0 input values can be verified: 23" ){
      REQUIRE( 23 == plotr.card0.nplt.value );
      REQUIRE( 0  == plotr.card0.nplt0.value );
    }
    THEN( "the Card1 input values can be verified: 1 1 0.1 1" ){
      REQUIRE( 1 == plotr.card1.lori.value );
      REQUIRE( 1 == plotr.card1.istyle.value );
      REQUIRE( Approx( 0.1 ) == plotr.card1.size.value );
      REQUIRE( 1 == plotr.card1.ipcol.value );
    }
    THEN( "the curves variable should have a length of 1" ){
      REQUIRE( 1 == plotr.curves.size() );
    }
    THEN(
    "the Card2 input values can be verified: 1 7 1.1 2.1 1.2 1.3 5.0 5.1 0.1" ){
      REQUIRE( 1 == plotr.curves[0].first.iplot.value );
      REQUIRE( 7 == plotr.curves[0].first.iwcol.value );
      REQUIRE( Approx( 1.1 ) == plotr.curves[0].first.factx.value );
      REQUIRE( Approx( 2.1 ) == plotr.curves[0].first.facty.value );
      REQUIRE( Approx( 1.2 ) == plotr.curves[0].first.xll.value );
      REQUIRE( Approx( 1.3 ) == plotr.curves[0].first.yll.value );
      REQUIRE( Approx( 5.0 ) == plotr.curves[0].first.ww.value );
      REQUIRE( Approx( 5.1 ) == plotr.curves[0].first.wh.value );
      REQUIRE( Approx( 0.1 ) == plotr.curves[0].first.wr.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3_1 == plotr.curves[0].second.plot->card3.title.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( sCard3a_1 == plotr.curves[0].second.plot->card3a.title.value );
    }
    THEN( "the Card4 input values can be verified: -1 1 2 0" ){
      REQUIRE( -1 == plotr.curves[0].second.plot->card4.itype.value );
      REQUIRE( 1 == plotr.curves[0].second.plot->card4.jtype.value );
      REQUIRE( 2 == plotr.curves[0].second.plot->card4.igrid.value );
      REQUIRE( 0 == plotr.curves[0].second.plot->card4.ileg.value );
      REQUIRE( std::nullopt ==
               plotr.curves[0].second.plot->card4.xtag.value );
      REQUIRE( std::nullopt ==
               plotr.curves[0].second.plot->card4.ytag.value );
    }

    THEN( "the Card5 input values can be verified: 0.1 100.1 1.0" ){
      REQUIRE( Approx( 0.1 ) == plotr.curves[0].second.plot->card5.el.value );
      REQUIRE( Approx( 100.1 ) == plotr.curves[0].second.plot->card5.eh.value );
      REQUIRE( Approx( 1.0 ) == 
               plotr.curves[0].second.plot->card5.xstep.value );
    }
    THEN( "the Card5a input values can be verified" ){
      REQUIRE( sCard5a_1 == plotr.curves[0].second.plot->card5a.xlabl.value );
    }

    THEN( "the Card6 input values can be verified: 0.2 100.2 2.0" ){
      REQUIRE( Approx( 0.2 ) == plotr.curves[0].second.plot->card6.yl.value );
      REQUIRE( Approx( 100.2 ) == plotr.curves[0].second.plot->card6.yh.value );
      REQUIRE( Approx( 2.0 ) == 
               plotr.curves[0].second.plot->card6.ystep.value );
    }
    THEN( "the Card6a input values can be verified" ){
      REQUIRE( sCard6a_1 == plotr.curves[0].second.plot->card6a.ylabl.value );
    }

    THEN( "the Card7 input values can be verified: -10.0 10.0 0.001" ){
      REQUIRE( Approx( -10.0 ) == 
               plotr.curves[0].second.plot->card7->first.rbot.value );
      REQUIRE( Approx(  10.0 ) == 
               plotr.curves[0].second.plot->card7->first.rtop.value );
      REQUIRE( Approx( 0.001 ) == 
               plotr.curves[0].second.plot->card7->first.rstep.value );
    }
    THEN( "the Card7a input values can be verified" ){
      REQUIRE( sCard7a_2 == 
               plotr.curves[0].second.plot->card7->second.rl.value );
    }

    THEN( "the Card8 input values can be verified: 1 23 9439 3 90 25.5 1" ){
      REQUIRE( 2 == plotr.curves[0].second.card8.iverf.value );
      REQUIRE( 23 == *( plotr.curves[0].second.card8.nin.value ) );
      REQUIRE( 9439 == *( plotr.curves[0].second.card8.matd.value ) );
      REQUIRE( 5 == *( plotr.curves[0].second.card8.mfd.value ) );
      REQUIRE( 90 == *( plotr.curves[0].second.card8.mtd.value ) );
      REQUIRE( 25.5 * dimwits::kelvin == 
               *( plotr.curves[0].second.card8.temper.value ) );
      REQUIRE( 1 == *( plotr.curves[0].second.card8.nth.value ) );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.ntpnkh );
    }

    THEN( "the Card9 input values can be verified: 5 1 1 1 1 0" ){
      REQUIRE( 5 == plotr.curves[0].second.card9.icon.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.isym.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.idash.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.iccol.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.ithick.value );
      REQUIRE( 0 == plotr.curves[0].second.card9.ishade.value );
    }

    THEN( "the Card11 input values can be verified: 15,-15,15,2.5,6.5,2.5" ){
      REQUIRE(  15.0 == plotr.curves[0].second.card11->xv.value );
      REQUIRE( -15.0 == plotr.curves[0].second.card11->yv.value );
      REQUIRE(  15.0 == plotr.curves[0].second.card11->zv.value );
      REQUIRE( 2.5 == plotr.curves[0].second.card11->x3.value );
      REQUIRE( 6.5 == plotr.curves[0].second.card11->y3.value );
      REQUIRE( 2.5 == plotr.curves[0].second.card11->z3.value );
    }

    THEN( "the remaining cards are empty" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.card10 );
      REQUIRE( std::nullopt == plotr.curves[0].second.card10a );
      REQUIRE( std::nullopt == plotr.curves[0].second.freeform );
    }
  }//WHEN
// Freeform input
//std::string sCard4_3( "1 /\n" );
//std::string sCard5_3( " /\n" );
//std::string sCard5a_3( " /\n" );
//std::string sCard6_3( " /\n" );
//std::string sCard6a_3( " /\n" );
// No card 7 or 7a.
//std::string sCard8_3( " 0 /\n" );
// No card 10 or 10a or 11.
//std::string sCard12_3( " 0 /\n" );
//std::string sCard13_3_1( " 1.0 2.0 1.5 2.5 0.5 1.5 /\n" );
//std::string sCard13_3_2( " 5.0 5.0 0 0 0 0 /\n" );
//std::string sCard13_3_3( " 20.1 21.2 10.0 30.0 10.0 25.0 /\n" );
//std::string sCard13_3_4( " /\n" );

  WHEN( "A valid freeform input" ){
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + " /\n" // empty title
      + " /\n" // empty title
      + sCard4_3 // 1 0 2 0
      + sCard5_3
      + sCard5a_3
      + sCard6_3
      + sCard6a_3
      + sCard8_3
      + sCard9_1
      + sCard12_3
      + sCard13_3_1
      + sCard13_3_2
      + sCard13_3_3
      + sCard13_3_4
      + sCard2_2
    ) );

    PLOTR plotr( iss );

    THEN( "the Card0 input values can be verified: 23" ){
      REQUIRE( 23 == plotr.card0.nplt.value );
      REQUIRE( 0  == plotr.card0.nplt0.value );
    }
    THEN( "the Card1 input values can be verified: 1 1 0.1 1" ){
      REQUIRE( 1 == plotr.card1.lori.value );
      REQUIRE( 1 == plotr.card1.istyle.value );
      REQUIRE( Approx( 0.1 ) == plotr.card1.size.value );
      REQUIRE( 1 == plotr.card1.ipcol.value );
    }
    THEN( "the curves variable should have a length of 1" ){
      REQUIRE( 1 == plotr.curves.size() );
    }
    THEN(
    "the Card2 input values can be verified: 1 7 1.1 2.1 1.2 1.3 5.0 5.1 0.1" ){
      REQUIRE( 1 == plotr.curves[0].first.iplot.value );
      REQUIRE( 7 == plotr.curves[0].first.iwcol.value );
      REQUIRE( Approx( 1.1 ) == plotr.curves[0].first.factx.value );
      REQUIRE( Approx( 2.1 ) == plotr.curves[0].first.facty.value );
      REQUIRE( Approx( 1.2 ) == plotr.curves[0].first.xll.value );
      REQUIRE( Approx( 1.3 ) == plotr.curves[0].first.yll.value );
      REQUIRE( Approx( 5.0 ) == plotr.curves[0].first.ww.value );
      REQUIRE( Approx( 5.1 ) == plotr.curves[0].first.wh.value );
      REQUIRE( Approx( 0.1 ) == plotr.curves[0].first.wr.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( PLOTR::Card3::Title::defaultValue() == 
               plotr.curves[0].second.plot->card3.title.value );
    }
    THEN( "the Card3 input values can be verified" ){
      REQUIRE( PLOTR::Card3a::Title::defaultValue() == 
               plotr.curves[0].second.plot->card3a.title.value );
    }
    THEN( "the Card4 input values can be verified: 1" ){
      REQUIRE( 1 == plotr.curves[0].second.plot->card4.itype.value );
      REQUIRE( 0 == plotr.curves[0].second.plot->card4.jtype.value );
      REQUIRE( 2 == plotr.curves[0].second.plot->card4.igrid.value );
      REQUIRE( 0 == plotr.curves[0].second.plot->card4.ileg.value );
      REQUIRE( std::nullopt ==
               plotr.curves[0].second.plot->card4.xtag.value );
      REQUIRE( std::nullopt ==
               plotr.curves[0].second.plot->card4.ytag.value );
    }

    THEN( "the Card5 input values can be verified: default values" ){
      REQUIRE( Approx( 0.0 ) == plotr.curves[0].second.plot->card5.el.value );
      REQUIRE( Approx( 0.0 ) == plotr.curves[0].second.plot->card5.eh.value );
      REQUIRE( Approx( 1.0 ) == 
               plotr.curves[0].second.plot->card5.xstep.value );
    }
    THEN( "the Card5a input values can be verified" ){
      REQUIRE( PLOTR::Card5a::Xlabl::defaultValue() ==
               plotr.curves[0].second.plot->card5a.xlabl.value );
    }

    THEN( "the Card6 input values can be verified: default values" ){
      REQUIRE( Approx( 0.0 ) == plotr.curves[0].second.plot->card6.yl.value );
      REQUIRE( Approx( 0.0 ) == plotr.curves[0].second.plot->card6.yh.value );
      REQUIRE( Approx( 1.0 ) == 
               plotr.curves[0].second.plot->card6.ystep.value );
    }
    THEN( "the Card6a input values can be verified" ){
      REQUIRE( PLOTR::Card6a::Ylabl::defaultValue() ==
               plotr.curves[0].second.plot->card6a.ylabl.value );
    }

    THEN( "the Card8 input values can be verified: 0" ){
      REQUIRE( 0 == plotr.curves[0].second.card8.iverf.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.nin.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.matd.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.mfd.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.mtd.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.temper.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.nth.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.card8.ntpnkh );
    }

    THEN( "the Card9 input values can be verified: 5 1 1 1 1 0" ){
      REQUIRE( 5 == plotr.curves[0].second.card9.icon.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.isym.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.idash.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.iccol.value );
      REQUIRE( 1 == plotr.curves[0].second.card9.ithick.value );
      REQUIRE( 0 == plotr.curves[0].second.card9.ishade.value );
    }
//std::string sCard12_3( " 0 /\n" );
//std::string sCard13_3_1( " 1.0 2.0 1.5 2.5 0.5 1.5 /\n" );
//std::string sCard13_3_2( " 5.0 5.0 0 0 0 0 /\n" );
//std::string sCard13_3_3( " 20.1 21.2 10.0 30.0 10.0 25.0 /\n" );
//std::string sCard13_3_4( " /\n" );
    THEN( "the Card12 input values can be verified: 0" ){
      REQUIRE( 0 == plotr.curves[0].second.freeform->card12.nform.value );
    }

    THEN( "the Card13 input values can be verified" ){
      REQUIRE( Approx( 1.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(0).xdata.value ) );
      REQUIRE( Approx( 2.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(0).ydata.value ) );
      REQUIRE( Approx( 1.5 ) ==
            *( plotr.curves[0].second.freeform->card13->at(0).yerr1.value ) );
      REQUIRE( Approx( 2.5 ) ==
            *( plotr.curves[0].second.freeform->card13->at(0).yerr2.value ) );
      REQUIRE( Approx( 0.5 ) ==
            *( plotr.curves[0].second.freeform->card13->at(0).xerr1.value ) );
      REQUIRE( Approx( 1.5 ) ==
            *( plotr.curves[0].second.freeform->card13->at(0).xerr2.value ) );

      REQUIRE( Approx( 5.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(1).xdata.value ) );
      REQUIRE( Approx( 5.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(1).ydata.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(1).yerr1.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(1).yerr2.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(1).xerr1.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(1).xerr2.value ) );

      REQUIRE( Approx( 20.1 ) ==
            *( plotr.curves[0].second.freeform->card13->at(2).xdata.value ) );
      REQUIRE( Approx( 21.2 ) ==
            *( plotr.curves[0].second.freeform->card13->at(2).ydata.value ) );
      REQUIRE( Approx( 10.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(2).yerr1.value ) );
      REQUIRE( Approx( 30.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(2).yerr2.value ) );
      REQUIRE( Approx( 10.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(2).xerr1.value ) );
      REQUIRE( Approx( 25.0 ) ==
            *( plotr.curves[0].second.freeform->card13->at(2).xerr2.value ) );
    }

    THEN( "the remaining cards are empty" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card7 );
      REQUIRE( std::nullopt == plotr.curves[0].second.card10 );
      REQUIRE( std::nullopt == plotr.curves[0].second.card10a );
      REQUIRE( std::nullopt == plotr.curves[0].second.card11 );
    }
  }//WHEN
/*
  WHEN( "reading in a more complicated input, igg=1, iwt=-1" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 1 4 0 /\n"      // Card2 -> igg=1,iwt=1,lord=4,iprint=0
      + "'" + sCard3 + "' /\n" // Card3
      + "5 1 2 3 4 5 6 /\n"    // Card4
      + "0. 0. 0 0 1 6\n"      // Card5
      + "6 5\n"
      + "1.00000E-05 8.00000E-20 1.00000E+03 9.13415E-10 1.00000E+04 6.13955E-08 \n"
      + "1.00925E+04 6.17490E-08 1.01859E+04 6.09190E-08 1.02802E+04 6.19874E-08 /\n"
      + sCard6_7
    ) );

    GAMINR gaminr( iss );

    THEN( "the Card1 input values can be verified" ){
      REQUIRE( -30 == gaminr.card1.nendf.value );
      REQUIRE( -32 == gaminr.card1.npend.value );
      REQUIRE(   0 == gaminr.card1.ngam1.value );
      REQUIRE( -34 == gaminr.card1.ngam2.value );
    }
    THEN( "the Card2 input values can be verified" ){
      REQUIRE( 125 == gaminr.card2.matb.value );
      REQUIRE( 1 == gaminr.card2.igg.value );
      REQUIRE( 1 == gaminr.card2.iwt.value );
      REQUIRE( 4 == gaminr.card2.lord.value );
      REQUIRE( 0 == gaminr.card2.iprint.value );
    }
    THEN( "the Card6 input values can be verified" ){

      REQUIRE( 3 == gaminr.card6List.size() );
      int i;
      { i = 0;
        REQUIRE( 3 == gaminr.card6List[i].mfd.value );
        REQUIRE( 18 == gaminr.card6List[i].mtd.value );
        REQUIRE( "MF3 MT18" == gaminr.card6List[i].mtname.value );
      }
      { i = 1;
        REQUIRE( 3 == gaminr.card6List[i].mfd.value );
        REQUIRE( 102 == gaminr.card6List[i].mtd.value );
        REQUIRE( "MF3 MT102" == gaminr.card6List[i].mtname.value );
      }
      { i = 2;
        REQUIRE( 10 == gaminr.card6List[i].mfd.value );
        REQUIRE( 0 == gaminr.card6List[i].mtd.value );
        REQUIRE( "" == gaminr.card6List[i].mtname.value );
      }
      { i = 3;
        REQUIRE( 0 == gaminr.card6List[i].mfd.value );
        REQUIRE( 0 == gaminr.card6List[i].mtd.value );
        REQUIRE( "" == gaminr.card6List[i].mtname.value );
      }
    }
    THEN( "the Card7 input values can be verified" ){
      REQUIRE( 1 == gaminr.card7List.size() );
      REQUIRE( 9235 == gaminr.card7List[0].matd.value );
      REQUIRE( 0 == gaminr.card7List[1].matd.value );
    }

    THEN( "the Card4 input values can be verified" ){
      auto card4 = (*gaminr.card4);
      REQUIRE( 5 == card4.ngg.value );
      REQUIRE( 6 == card4.egg.value.size() );
      REQUIRE( 1*dimwits::electronVolt == card4.egg.value[0] );
      REQUIRE( 2*dimwits::electronVolt == card4.egg.value[1] );
      REQUIRE( 3*dimwits::electronVolt == card4.egg.value[2] );
      REQUIRE( 4*dimwits::electronVolt == card4.egg.value[3] );
      REQUIRE( 5*dimwits::electronVolt == card4.egg.value[4] );
      REQUIRE( 6*dimwits::electronVolt == card4.egg.value[5] );
    }
    THEN( "the card5 values can be verified" ){
      auto card5 = (*gaminr.card5);
      REQUIRE( 1E-5        == card5.wght.value.x()[0] );
      REQUIRE( 1E3         == card5.wght.value.x()[1] );
      REQUIRE( 1E4         == card5.wght.value.x()[2] );
      REQUIRE( 1.00925E4   == card5.wght.value.x()[3] );
      REQUIRE( 1.01859E4   == card5.wght.value.x()[4] );
      REQUIRE( 1.02802E4   == card5.wght.value.x()[5] );

      REQUIRE( 8.0E-20     == card5.wght.value.y()[0] );
      REQUIRE( 9.13415E-10 == card5.wght.value.y()[1] );
      REQUIRE( 6.13955E-8  == card5.wght.value.y()[2] );
      REQUIRE( 6.17490E-8  == card5.wght.value.y()[3] );
      REQUIRE( 6.09190E-8  == card5.wght.value.y()[4] );
      REQUIRE( 6.19874E-8  == card5.wght.value.y()[5] );
    }
  }
}

SCENARIO( "Parsing invalid GAMINR input" ){
  WHEN( "too many gamm groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + "4 1 2 3 4 5 6/\n"       // Card4
      + sCard6_7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
  WHEN( "too few gamma groups" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 1 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + "4 1 2 3 4 /\n"       // Card4
      + sCard6_7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
  WHEN( "No terminating mfd=0" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 0 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + "3 18 'MF3 MT18' /\n"         // Card 6.1
      + "3 102 'MF3 MT102' /\n"       // Card 6.2
      + "10 /\n"                      // Card 6.3
      // + "0 /\n"                       // Card 6.4
      + "9235 /\n"                       // Card7
      + "0 /\n"                       // Card7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
  WHEN( "No terminating matd=0" ){
    iRecordStream<char> iss( std::istringstream(
      sCard1
      + "125 0 2 4 1 /\n"         // Card2
      + "'" + sCard3 + "' /\n"
      + "3 18 'MF3 MT18' /\n"         // Card 6.1
      + "3 102 'MF3 MT102' /\n"       // Card 6.2
      + "10 /\n"                      // Card 6.3
      + "0 /\n"                       // Card 6.4
      + "9235 /\n"                       // Card7
      // + "0 /\n"                       // Card7
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( GAMINR( iss ) );
    }
  }
*/
}
SCENARIO( "Parsing invalid PLOTR input" ){
  WHEN( "passing input without terminating card 2 (iplot=99)" ){
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' /\n"
      + sCard4_1
      + sCard5_1
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard8_1
      + sCard9_1
      + "'" + sCard10_1 + "' /\n"
      + sCard10a_1
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PLOTR( iss ) );
    }
  }
  WHEN( "passing input with final card 2, but with non-terminating value" ){
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' /\n"
      + sCard4_1
      + sCard5_1
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard8_1
      + sCard9_1
      + "'" + sCard10_1 + "' /\n"
      + sCard10a_1
      + " 12 /\n"
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PLOTR( iss ) );
    }
  }
  WHEN( "Extra value on card 3a" ){
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' 9 /\n"
      + sCard4_1
      + sCard5_1
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard8_1
      + sCard9_1
      + "'" + sCard10_1 + "' /\n"
      + sCard10a_1
      + sCard2_2
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PLOTR( iss ) );
    }
  }
  WHEN( "Card 8 iverf=0, but no card11 and/or 12 input" ){
    std::string sCard8_2( "0 23 9439 5 90 25.5 1 /\n" );
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' /\n"
      + sCard4_1
      + sCard5_1
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard8_2
      + sCard9_1
      + "'" + sCard10_1 + "' /\n"
      + sCard10a_1
      + sCard2_2
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PLOTR( iss ) );
    }
  }
  WHEN( "X-axis is logarithmic but lower bound is set to 0.0" ){
    std::string sCard8_2( "0 23 9439 5 90 25.5 1 /\n" );
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' /\n"
      + " 3 0 2 0 /\n"
      + " 0.0 10.0 0.3 /\n"
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard8_1
      + sCard9_1
      + "'" + sCard10_1 + "' /\n"
      + sCard10a_1
      + sCard2_2
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PLOTR( iss ) );
    }
  }
  WHEN( "Just skipped Card9, which is required." ){
    iRecordStream<char> iss( std::istringstream(
      sCard0
      + sCard1
      + sCard2_1
      + "'" + sCard3_1 + "' /\n"
      + "'" + sCard3a_1 + "' /\n"
      + sCard4_1
      + sCard5_1
      + "'" + sCard5a_1 + "' /\n"
      + sCard6_1
      + "'" + sCard6a_1 + "' /\n"
      + sCard8_1
      + "'" + sCard10_1 + "' /\n"
      + sCard10a_1
      + sCard2_2
    ) );

    THEN( "an exception is thrown" ){
      REQUIRE_THROWS( PLOTR( iss ) );
    }
  }
}
