Driver operator()(){

  // For passing arbitrary arguments to modules
  auto args = nlohmann::json::object();

  auto outputPair = this->manager->output( 
      static_cast< modern::Sequence*>(nullptr) );
  const auto& output = outputPair.first;
  // const auto& error = outputPair.second;
  (*output) << banner;
  output->flush();

  legacy::Sequence::Factory legacyFactory( *(this->manager), this->legacy );
  modern::Sequence::Factory modernFactory( *(this->manager) );

  auto makeProcessor = []( auto& set, auto& factory ){
    return [&]( auto& label, auto& queue ){
      // If the label is among the allowed modules in factory
      if ( set.count(label) ){
        queue.push( factory( label ) );
        return true;
      }
      return false;
    };
  };
  auto legacyProcessor = makeProcessor( this->legacy, legacyFactory );
  auto modernProcessor = makeProcessor( this->modern, modernFactory );

  Queue queue; 
  auto label = lipservice::Label::extract( manager->input() );

  auto cycle = [&]( auto& first, auto& second ){
    while( first( label, queue ) and second( label, queue ) ){ }
  };
  this->legacy.count( label ) ?
    cycle( legacyProcessor, modernProcessor ) :
    cycle( modernProcessor, legacyProcessor );

  if ( label != "STOP" ){
    Log::error( "Unrecognized routine label on line {}",
    manager->input().lineNumber );
    Log::info( "Requested routine: {}", label );
    throw std::exception();
  }

  if ( this->commandLine.verifyOnly ){ queue = Queue(); }

  return Driver( std::move( this->manager ), 
                 std::move( queue ), 
                 std::move( args ) );
}
