#include "valueholder/vh.hpp"
#include <stdexcept>

#include "valueholder/intger.hpp"

namespace zms {
  vh::vh(vhgtype vhg) {
    switch (vhg) {
      case vhgtype::INTGER: {
                              m_type = new INTGER();
                              break;
                            }
      case vhgtype::FLOAT: {
                              //m_type = new INTGER();  
                              break;
                            }
    }
  }
  void vh::set_value(type *t) {
    if(m_type->get_type() == t->get_type()) {
      m_type->copy(t);
    } else {
      throw std::runtime_error("zms::lowlev: envaled conversion\n");
    }
  }

  type &vh::get_value() {
    return *m_type;
  }
}
