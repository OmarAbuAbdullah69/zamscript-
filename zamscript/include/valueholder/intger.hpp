#include "core.hpp"
#include "n.hpp"
#include "vh.hpp"
#include <stdexcept>

namespace zms {
  class INTGER: public value {
    friend int extract(INTGER);
    public:
      INTGER(int value = 0)
        :m_value(value) {}

      virtual value_type get_type() const override{
        return s_get_type();
      }
      virtual void  copy(const value &other) override{
        if(chick_same_value(other)) {
          m_value = (*((INTGER *) &other)).m_value;
        } else {
          throw std::runtime_error("zms::error::low: value is not an INTGER\n");
        }
      }

      static int s_extract(vh_id vid) {
        value &v = core::instance().get_value(vid);
        if (value_type::INTGER == v.get_type()) {
          return (*((INTGER *) &v)).m_value;
        } else {
          throw std::runtime_error("zms::error::low: value is not an INTGER\n");
        }
        return -1;
      }
     
      inline int get_value() const{
        return m_value;
      }

    private:
      static value_type s_get_type() {
        return value_type::INTGER;
      }

      int m_value;
  };

}
