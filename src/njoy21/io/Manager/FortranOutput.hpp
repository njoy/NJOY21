public:

struct FileGaurd {
protected:
  bool owning = true;

public:  
  FileGaurd( std::string& path ){
    njoy_setup_output_file( &(path[0]), path.length() );
  }

  FileGaurd() = delete;
  FileGaurd( const FileGaurd& ) = delete;
  FileGaurd( FileGaurd&& other ) :
    owning( other.owning ){
    other.owning = false;
  }

  FileGaurd& operator=( const FileGaurd& ) = delete;
  FileGaurd& operator=( FileGaurd&& other ){
    this->owning = other.owning;
    other.owning = false;
    return *this;
  }
  
  ~FileGaurd(){ if ( owning ) { njoy_cleanup_output_file(); } }
};
