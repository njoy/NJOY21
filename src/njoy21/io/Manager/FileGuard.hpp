public:

struct IOPolicy {
  decltype(&njoy_setup_output_file) setup;
  decltype(&njoy_cleanup_output_file) cleanup;
};

static constexpr IOPolicy outputPolicy(){
  return IOPolicy{
    &njoy_setup_output_file,
    &njoy_cleanup_output_file
  };
}

static constexpr const IOPolicy errorPolicy(){
  return IOPolicy{
    &njoy_setup_error_file,
    &njoy_cleanup_error_file
  };
}

struct FileGuard {
protected:
  IOPolicy ioPolicy;
  bool owning = true;

public:  
  FileGuard( std::string& path,
             IOPolicy policy ):
    ioPolicy( policy )
  {
    ioPolicy.setup( &(path[0]), path.length() );
  }

  FileGuard() : owning(false){}
  FileGuard( const FileGuard& ) = delete;
  FileGuard( FileGuard&& other ) :
    ioPolicy( other.ioPolicy ),
    owning( other.owning )
  {
    other.owning = false;
  }

  FileGuard& operator=( const FileGuard& ) = delete;
  FileGuard& operator=( FileGuard&& other ){
    this->ioPolicy = other.ioPolicy;
    this->owning = other.owning;
    other.owning = false;
    return *this;
  }
  
  ~FileGuard(){ if ( owning ) { ioPolicy.cleanup(); } }
  void disown(){ this->owning = false; }
};
