#pragma once


#include <memory>
namespace zms {
  enum class value_type {
    INTGER = 0,
    FLOAT,
  };
  class value {
    friend class vh;
    public:
      value(const value &) {}
      inline bool chick_same_value(const value &o) {
        return (o.m_vt == m_vt) ? true : false;
      }
      virtual ~value(){}
      
    virtual value_type get_type() const = 0;
    protected:
      value(){}
    private:
      virtual void copy(const value &) = 0;
      value_type m_vt;
  };
  class vh {
    friend class unit;
    friend class core;
    public:
      ~vh();
      vh(const vh &o);
    private:
      vh(value_type vhg);
      void set_value(const value &v);
      value &get_value();
      std::shared_ptr<value> m_type;
      bool m_constant;
  };

  
}
