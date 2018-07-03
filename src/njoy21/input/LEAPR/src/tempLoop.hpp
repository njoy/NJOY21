template< typename Istream >
static TempLoop 
buildTempLoop( Istream& is, Card3& card3, Card5& card5, Card6& card6 ){
  const int maxloop = ( card6.controlTuple->b7.value == 0 ) ?
                      card3.ntempr.value*( card6.nss.value + 1 ) :
                      card3.ntempr.value;

  TempLoop myTempLoop;
  for( int i = 0; i < maxloop; i++ ){
    myTempLoop.emplace_back( buildTempLoopIter( is, card5, i ) );
  }
   
  return myTempLoop;
  
} 

