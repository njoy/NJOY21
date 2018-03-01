struct Wght : GROUPR::Card8b::Wght {
  static bool verify( const Value_t wght ){
    if( not GROUPR::Card8b::Wght::verify( wght ) ){
      auto w = std::find_if( wght.y().begin(), wght.y().end(), [](double v){
                                                            return v < 0.0; } );
  
      if( w != wght.y().end() ){
        Log::error( "Wght with value {} is less than zero.", *w );
        return false;
      }
    }

    return true;
  }
};
