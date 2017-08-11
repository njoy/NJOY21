
static TempLoopIter buildTempLoopIter( iRecordStream<char>& is, 
                                       Card5& card5, int& i ){

  auto card10 = Card10( is );
  if( i == 0 and card10.temp.value < 0.0 * dimwits::kelvin ){
    Log::info( "A negative card10 temp value indicates that the temperature\n"
               "specific parameters (cards 11 - 19) will not be provided,\n"
	       "and instead parameters from a previous temperature iteration\n"
	       "will be used.\n"
	       "\n"
	       "Thus, the first temperature loop cannot have a negative\n"
	       "value, since there are no previous loops to reference." );
    throw( "Invalid Card10 temp input" );
  }
  auto tempSpecificTuple = (card10.temp.value > 0.0 * dimwits::kelvin ) ?
    buildTempSpecificTuple( is, card5 ) : std::nullopt;
  return TempLoopIter( card10, tempSpecificTuple );

}


