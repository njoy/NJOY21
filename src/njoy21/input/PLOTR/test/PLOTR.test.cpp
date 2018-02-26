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
// No card 9 or 10 or 10a or 11.
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
      REQUIRE( sCard3_1 == plotr.curves[0].second.plot->card3.t1.value );
    }
    THEN( "the Card3a input values can be verified" ){
      REQUIRE( sCard3a_1 == plotr.curves[0].second.plot->card3a.t2.value );
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
      REQUIRE( Approx( 0.1 ) == 
                             *( plotr.curves[0].second.plot->card5.el.value ) );
      REQUIRE( Approx( 100.1 ) ==
                             *( plotr.curves[0].second.plot->card5.eh.value ) );
      REQUIRE( Approx( 1.0 ) == 
                          *( plotr.curves[0].second.plot->card5.xstep.value ) );
    }
    THEN( "the Card5a input values can be verified" ){
      REQUIRE( sCard5a_1 == plotr.curves[0].second.plot->card5a.xlabl.value );
    }

    THEN( "the Card6 input values can be verified: 0.2 100.2 2.0" ){
      REQUIRE( Approx( 0.2 ) == 
                             *( plotr.curves[0].second.plot->card6.yl.value ) );
      REQUIRE( Approx( 100.2 ) ==
                             *( plotr.curves[0].second.plot->card6.yh.value ) );
      REQUIRE( Approx( 2.0 ) == 
                          *( plotr.curves[0].second.plot->card6.ystep.value ) );
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
      REQUIRE( 5 == plotr.curves[0].second.card9->icon.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->isym.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->idash.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->iccol.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->ithick.value );
      REQUIRE( 0 == plotr.curves[0].second.card9->ishade.value );
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
//      + sCard9_1
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
      REQUIRE( sCard3_1 == plotr.curves[0].second.plot->card3.t1.value );
    }
    THEN( "the Card3a input values can be verified" ){
      REQUIRE( sCard3a_1 == plotr.curves[0].second.plot->card3a.t2.value );
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
      REQUIRE( Approx( 0.1 ) == 
                             *( plotr.curves[0].second.plot->card5.el.value ) );
      REQUIRE( Approx( 100.1 ) ==
                             *( plotr.curves[0].second.plot->card5.eh.value ) );
      REQUIRE( Approx( 1.0 ) == 
                          *( plotr.curves[0].second.plot->card5.xstep.value ) );
    }
    THEN( "the Card5a input values can be verified" ){
      REQUIRE( sCard5a_1 == plotr.curves[0].second.plot->card5a.xlabl.value );
    }

    THEN( "the Card6 input values can be verified: 0.2 100.2 2.0" ){
      REQUIRE( Approx( 0.2 ) == 
                             *( plotr.curves[0].second.plot->card6.yl.value ) );
      REQUIRE( Approx( 100.2 ) ==
                             *( plotr.curves[0].second.plot->card6.yh.value ) );
      REQUIRE( Approx( 2.0 ) == 
                          *( plotr.curves[0].second.plot->card6.ystep.value ) );
    }
    THEN( "the Card6a input values can be verified" ){
      REQUIRE( sCard6a_1 == plotr.curves[0].second.plot->card6a.ylabl.value );
    }

    THEN( "the Card7 input values can be verified: -10.0 10.0 0.001" ){
      REQUIRE( Approx( -10.0 ) == 
               *( plotr.curves[0].second.plot->card7->first.rbot.value ) );
      REQUIRE( Approx(  10.0 ) == 
               *( plotr.curves[0].second.plot->card7->first.rtop.value ) );
      REQUIRE( Approx( 0.001 ) == 
               *( plotr.curves[0].second.plot->card7->first.rstep.value ) );
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
      REQUIRE( 5 == plotr.curves[0].second.card9->icon.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->isym.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->idash.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->iccol.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->ithick.value );
      REQUIRE( 0 == plotr.curves[0].second.card9->ishade.value );
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
      REQUIRE( PLOTR::Card3::T1::defaultValue() == 
               plotr.curves[0].second.plot->card3.t1.value );
    }
    THEN( "the Card3a input values can be verified" ){
      REQUIRE( PLOTR::Card3a::T2::defaultValue() == 
               plotr.curves[0].second.plot->card3a.t2.value );
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
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card5.el.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card5.eh.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card5.xstep.value );
    }
    THEN( "the Card5a input values can be verified" ){
      REQUIRE( PLOTR::Card5a::Xlabl::defaultValue() ==
               plotr.curves[0].second.plot->card5a.xlabl.value );
    }

    THEN( "the Card6 input values can be verified: default values" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card6.yl.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card6.yh.value );
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card6.ystep.value );
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
      REQUIRE( 5 == plotr.curves[0].second.card9->icon.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->isym.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->idash.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->iccol.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->ithick.value );
      REQUIRE( 0 == plotr.curves[0].second.card9->ishade.value );
    }
    THEN( "the Card12 input values can be verified: 0" ){
      REQUIRE( 0 == plotr.curves[0].second.freeform->card12.nform.value );
    }

    THEN( "the Card13 input values can be verified" ){
      REQUIRE( Approx( 1.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(0).xdata.value ) );
      REQUIRE( Approx( 2.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(0).ydata.value ) );
      REQUIRE( Approx( 1.5 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(0).yerr1.value ) );
      REQUIRE( Approx( 2.5 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(0).yerr2.value ) );
      REQUIRE( Approx( 0.5 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(0).xerr1.value ) );
      REQUIRE( Approx( 1.5 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(0).xerr2.value ) );

      REQUIRE( Approx( 5.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(1).xdata.value ) );
      REQUIRE( Approx( 5.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(1).ydata.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(1).yerr1.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(1).yerr2.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(1).xerr1.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(1).xerr2.value ) );

      REQUIRE( Approx( 20.1 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(2).xdata.value ) );
      REQUIRE( Approx( 21.2 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(2).ydata.value ) );
      REQUIRE( Approx( 10.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(2).yerr1.value ) );
      REQUIRE( Approx( 30.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(2).yerr2.value ) );
      REQUIRE( Approx( 10.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(2).xerr1.value ) );
      REQUIRE( Approx( 25.0 ) ==
            *( plotr.curves[0].second.freeform->card13List->at(2).xerr2.value ) );
    }

    THEN( "the remaining cards are empty" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card7 );
      REQUIRE( std::nullopt == plotr.curves[0].second.card10 );
      REQUIRE( std::nullopt == plotr.curves[0].second.card10a );
      REQUIRE( std::nullopt == plotr.curves[0].second.card11 );
    }
  }//WHEN
  WHEN( "reading in more than one curve" ){
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
    THEN( "the curves variable should have a length of 2" ){
      REQUIRE( 2 == plotr.curves.size() );
    }
    THEN( "the first Card2 input values can be verified:"
          "1 7 1.1 2.1 1.2 1.3 5.0 5.1 0.1" ){
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
    THEN( "the first Card3 input values can be verified" ){
      REQUIRE( sCard3_1 == plotr.curves[0].second.plot->card3.t1.value );
    }
    THEN( "the first Card3a input values can be verified" ){
      REQUIRE( sCard3a_1 == plotr.curves[0].second.plot->card3a.t2.value );
    }
    THEN( "the first Card4 input values can be verified: 1 0 2 1 10.0 10.0" ){
      REQUIRE( 1 == plotr.curves[0].second.plot->card4.itype.value );
      REQUIRE( 0 == plotr.curves[0].second.plot->card4.jtype.value );
      REQUIRE( 2 == plotr.curves[0].second.plot->card4.igrid.value );
      REQUIRE( 2 == plotr.curves[0].second.plot->card4.ileg.value );
      REQUIRE( Approx( 10.0 ) == 
               *( plotr.curves[0].second.plot->card4.xtag.value ) );
      REQUIRE( Approx( 10.0 ) == 
               *( plotr.curves[0].second.plot->card4.ytag.value ) );
    }

    THEN( "the first Card5 input values can be verified: 0.1 100.1 1.0" ){
      REQUIRE( Approx( 0.1 ) == 
                             *( plotr.curves[0].second.plot->card5.el.value ) );
      REQUIRE( Approx( 100.1 ) ==
                             *( plotr.curves[0].second.plot->card5.eh.value ) );
      REQUIRE( Approx( 1.0 ) == 
                          *( plotr.curves[0].second.plot->card5.xstep.value ) );
    }
    THEN( "the first Card5a input values can be verified" ){
      REQUIRE( sCard5a_1 == plotr.curves[0].second.plot->card5a.xlabl.value );
    }

    THEN( "the first Card6 input values can be verified: 0.2 100.2 2.0" ){
      REQUIRE( Approx( 0.2 ) == 
                             *( plotr.curves[0].second.plot->card6.yl.value ) );
      REQUIRE( Approx( 100.2 ) ==
                             *( plotr.curves[0].second.plot->card6.yh.value ) );
      REQUIRE( Approx( 2.0 ) == 
                          *( plotr.curves[0].second.plot->card6.ystep.value ) );
    }
    THEN( "the first Card6a input values can be verified" ){
      REQUIRE( sCard6a_1 == plotr.curves[0].second.plot->card6a.ylabl.value );
    }

    THEN( "first Card7 is unused" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.plot->card7 );
    }

    THEN( "the first Card8 input values can be verified:"
          "1 23 9439 3 90 25.5 1" ){
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

    THEN( "the first Card9 input values can be verified: 5 1 1 1 1 0" ){
      REQUIRE( 5 == plotr.curves[0].second.card9->icon.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->isym.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->idash.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->iccol.value );
      REQUIRE( 1 == plotr.curves[0].second.card9->ithick.value );
      REQUIRE( 0 == plotr.curves[0].second.card9->ishade.value );
    }

    THEN( "the first Card10 input values can be verified" ){
      REQUIRE( sCard10_1 == plotr.curves[0].second.card10->aleg.value );
    }

    THEN( "the first Card10a input values can be verified: 20.0 20.0 25.0" ){
      REQUIRE( Approx( 20.0 ) == plotr.curves[0].second.card10a->xtag.value );
      REQUIRE( Approx( 20.0 ) == plotr.curves[0].second.card10a->ytag.value );
      REQUIRE( Approx( 25.0 ) == plotr.curves[0].second.card10a->xpoint.value );
    }

    THEN( "the remaining cards are empty for the first curve" ){
      REQUIRE( std::nullopt == plotr.curves[0].second.card11 );
      REQUIRE( std::nullopt == plotr.curves[0].second.freeform );
    }

    THEN( "the second Card2 input values can be verified:"
          "1 7 1.1 2.1 1.2 1.3 5.0 5.1 0.1" ){
      REQUIRE( 1 == plotr.curves[1].first.iplot.value );
      REQUIRE( 7 == plotr.curves[1].first.iwcol.value );
      REQUIRE( Approx( 1.1 ) == plotr.curves[1].first.factx.value );
      REQUIRE( Approx( 2.1 ) == plotr.curves[1].first.facty.value );
      REQUIRE( Approx( 1.2 ) == plotr.curves[1].first.xll.value );
      REQUIRE( Approx( 1.3 ) == plotr.curves[1].first.yll.value );
      REQUIRE( Approx( 5.0 ) == plotr.curves[1].first.ww.value );
      REQUIRE( Approx( 5.1 ) == plotr.curves[1].first.wh.value );
      REQUIRE( Approx( 0.1 ) == plotr.curves[1].first.wr.value );
    }
    THEN( "the second Card3 input values can be verified" ){
      REQUIRE( PLOTR::Card3::T1::defaultValue() == 
               plotr.curves[1].second.plot->card3.t1.value );
    }
    THEN( "the second Card3a input values can be verified" ){
      REQUIRE( PLOTR::Card3a::T2::defaultValue() == 
               plotr.curves[1].second.plot->card3a.t2.value );
    }
    THEN( "the second Card4 input values can be verified: 1" ){
      REQUIRE( 1 == plotr.curves[1].second.plot->card4.itype.value );
      REQUIRE( 0 == plotr.curves[1].second.plot->card4.jtype.value );
      REQUIRE( 2 == plotr.curves[1].second.plot->card4.igrid.value );
      REQUIRE( 0 == plotr.curves[1].second.plot->card4.ileg.value );
      REQUIRE( std::nullopt ==
               plotr.curves[1].second.plot->card4.xtag.value );
      REQUIRE( std::nullopt ==
               plotr.curves[1].second.plot->card4.ytag.value );
    }

    THEN( "the second Card5 input values can be verified: default values" ){
      REQUIRE( std::nullopt == plotr.curves[1].second.plot->card5.el.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.plot->card5.eh.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.plot->card5.xstep.value );
    }
    THEN( "the second Card5a input values can be verified" ){
      REQUIRE( PLOTR::Card5a::Xlabl::defaultValue() ==
               plotr.curves[1].second.plot->card5a.xlabl.value );
    }

    THEN( "the second Card6 input values can be verified: default values" ){
      REQUIRE( std::nullopt == plotr.curves[1].second.plot->card6.yl.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.plot->card6.yh.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.plot->card6.ystep.value );
    }
    THEN( "the second Card6a input values can be verified" ){
      REQUIRE( PLOTR::Card6a::Ylabl::defaultValue() ==
               plotr.curves[1].second.plot->card6a.ylabl.value );
    }

    THEN( "the second Card8 input values can be verified: 0" ){
      REQUIRE( 0 == plotr.curves[1].second.card8.iverf.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.card8.nin.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.card8.matd.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.card8.mfd.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.card8.mtd.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.card8.temper.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.card8.nth.value );
      REQUIRE( std::nullopt == plotr.curves[1].second.card8.ntpnkh );
    }

    THEN( "the second Card9 input values can be verified: 5 1 1 1 1 0" ){
      REQUIRE( 5 == plotr.curves[1].second.card9->icon.value );
      REQUIRE( 1 == plotr.curves[1].second.card9->isym.value );
      REQUIRE( 1 == plotr.curves[1].second.card9->idash.value );
      REQUIRE( 1 == plotr.curves[1].second.card9->iccol.value );
      REQUIRE( 1 == plotr.curves[1].second.card9->ithick.value );
      REQUIRE( 0 == plotr.curves[1].second.card9->ishade.value );
    }
    THEN( "the second Card12 input values can be verified: 0" ){
      REQUIRE( 0 == plotr.curves[1].second.freeform->card12.nform.value );
    }

    THEN( "the second Card13 input values can be verified" ){
      REQUIRE( Approx( 1.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(0).xdata.value ) );
      REQUIRE( Approx( 2.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(0).ydata.value ) );
      REQUIRE( Approx( 1.5 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(0).yerr1.value ) );
      REQUIRE( Approx( 2.5 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(0).yerr2.value ) );
      REQUIRE( Approx( 0.5 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(0).xerr1.value ) );
      REQUIRE( Approx( 1.5 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(0).xerr2.value ) );

      REQUIRE( Approx( 5.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(1).xdata.value ) );
      REQUIRE( Approx( 5.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(1).ydata.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(1).yerr1.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(1).yerr2.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(1).xerr1.value ) );
      REQUIRE( Approx( 0.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(1).xerr2.value ) );

      REQUIRE( Approx( 20.1 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(2).xdata.value ) );
      REQUIRE( Approx( 21.2 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(2).ydata.value ) );
      REQUIRE( Approx( 10.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(2).yerr1.value ) );
      REQUIRE( Approx( 30.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(2).yerr2.value ) );
      REQUIRE( Approx( 10.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(2).xerr1.value ) );
      REQUIRE( Approx( 25.0 ) ==
            *( plotr.curves[1].second.freeform->card13List->at(2).xerr2.value ) );
    }

    THEN( "the remaining cards are empty for the second curve" ){
      REQUIRE( std::nullopt == plotr.curves[1].second.plot->card7 );
      REQUIRE( std::nullopt == plotr.curves[1].second.card10 );
      REQUIRE( std::nullopt == plotr.curves[1].second.card10a );
      REQUIRE( std::nullopt == plotr.curves[1].second.card11 );
    }
  }//WHEN
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
