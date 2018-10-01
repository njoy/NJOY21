struct FileGuard {
protected:
  bool owning = true;

public:  
  FileGuard( std::string& path ){
    njoy_setup_output_file( &(path[0]), path.length() );
  }

  FileGuard() : owning(false){}
  FileGuard( const FileGuard& ) = delete;
  FileGuard( FileGuard&& other ) :
    owning( other.owning ){
    other.owning = false;
  }

  FileGuard& operator=( const FileGuard& ) = delete;
  FileGuard& operator=( FileGuard&& other ){
    this->owning = other.owning;
    other.owning = false;
    return *this;
  }
  
  ~FileGuard(){ if ( owning ) { njoy_cleanup_output_file(); } }
};
