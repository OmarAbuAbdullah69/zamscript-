#include "vh.hpp"
#include <stdexcept>

namespace zms {
  class INTGER: public type {
    friend int extract(INTGER);
    public:
      INTGER(int value = 0)
        :m_value(value) {}

      virtual vhgtype get_type() const override{
        return s_get_type();
      }
      virtual void  copy(const type *other) override{
        if(chick_same_type(*other)) {
          m_value = s_extract(*other);
        } else {
          throw std::runtime_error("zms::error::low: cannon't copy diffrent types\n");
        }
      }

      static int s_extract(const type &t) {
        if (vhgtype::INTGER == t.get_type()) {
          return (*((INTGER *) &t)).m_value;
        } else {
          throw std::runtime_error("zms::error::low: type is not an INTGER\n");
        }
        return -1;
      }
     
      inline int get_value() const{
        return m_value;
      }

    private:
      static vhgtype s_get_type() {
        return vhgtype::INTGER;
      }

      int m_value;
  };

}
