#include "valueholder/vh.hpp"
#include "valueholder/types.hpp"

namespace zms {
  vh::vh(value_type vhg) {
    switch (vhg) {
      case value_type::INTGER: {
                              m_type = std::shared_ptr<value>(new INTGER);
                              break;
                            }
      case value_type::FLOAT: {
                             //m_type = new INTGER();  
                              break;
                            }
    }
  }
  vh::vh(const vh &o)
    : m_type(o.m_type), m_constant(o.m_constant)
  {
  }

  vh::~vh() {
  }

  void vh::set_value(const value &v) {
    m_type->copy(v);
  }

  value &vh::get_value() {
    return *m_type;
  }
}
