namespace interface {

struct Routine {

  struct Sequence {
    virtual ~Sequence() = default;
    virtual void operator()() = 0;
  };

  virtual ~Routine() = default;
  virtual void operator()() = 0;
};

}
