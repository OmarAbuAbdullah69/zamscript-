#pragma once


namespace zms {
  enum class vhgtype {
    INTGER = 0,
    FLOAT,
  };
  class type {
    friend class vh;
    public:
      type(const type &) {}
      inline bool chick_same_type(const type & o) {
        return (o.m_gtype == m_gtype) ? true : false;
      } 
      
    virtual vhgtype get_type() const = 0;
    protected:
      type(){}
    private:
      virtual void copy(const type *) = 0;
      vhgtype m_gtype;
  };
  class vh {
    friend class unit;
    friend class core;
    private:
      vh(vhgtype vhg);
      void set_value(type *t);
      type &get_value();
      type *m_type;
      bool m_constant;
  };

  
}
