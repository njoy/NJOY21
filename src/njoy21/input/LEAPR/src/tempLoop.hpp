
static TempLoop 
buildTempLoop( iRecordStream<char>& is, Card3& card3, Card5& card5 ){

  TempLoop myTempLoop;
  for( int i = 0; i < card3.ntempr.value; i++ ){
    myTempLoop.emplace_back( buildTempLoopIter( is, card5, i ) );
  }
   
  return myTempLoop;
  
} 

