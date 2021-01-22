void operator()(){
  while ( this->queue.size() ){
    auto& routine = *( this->queue.front() );
    routine( this->args );
    this->queue.pop();
  }
}
